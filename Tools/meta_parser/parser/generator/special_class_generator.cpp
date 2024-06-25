#include "common/precompiled.h"

#include "generator/special_class_generator.h"

#include "language_types/class.h"
#include "template_manager/template_manager.h"

#include <map>
#include <set>

namespace Generator
{
    SpecialClassGenerator::SpecialClassGenerator(std::string                             source_directory,
                                             std::function<std::string(std::string)> get_include_function) :
        GeneratorInterface(source_directory + "/_generated/specialClass", source_directory, get_include_function)
    {
        prepareStatus(m_out_path);
    }
    void SpecialClassGenerator::prepareStatus(const std::string& path)
    {
        GeneratorInterface::prepareStatus(path);
        TemplateManager::getInstance()->loadTemplates(m_root_path, "commonSpecialClassGenFile");
        TemplateManager::getInstance()->loadTemplates(m_root_path, "allSpecialClassFile");
        return;
    }

    std::string SpecialClassGenerator::processFileName(const std::string& path)
    {
        auto relativeDir = fs::path(path).filename().replace_extension("specialClass.gen.h").string();
        return m_out_path + "/" + relativeDir;
    }

    int SpecialClassGenerator::generate(const std::string& path, const SchemaMoudle& schema, const std::unordered_map<std::string, SchemaMoudle>& moudle)
    {
        std::string file_path = processFileName(path);

        Mustache::data muatache_data;
        Mustache::data include_headfiles(Mustache::data::type::list);
        Mustache::data class_defines(Mustache::data::type::list);

        include_headfiles.push_back(Mustache::data("headfile_name", Utils::makeRelativePath(m_root_path, path).string()));

        static std::vector<std::string> s_specClassNames = { "Component", "ParticleEvolver" };

        auto processSpecClassFunc = [&](const std::string& specClassName) -> void {
            bool isSpecClass = false;
            std::shared_ptr<Class> curClass;
            for (auto class_temp : schema.classes)
            {
                if (!class_temp->shouldCompileFields())
                    continue;

                Mustache::data class_def;
                genClassRenderData(class_temp, class_def);

                if (class_temp->getClassName() == specClassName)
                {
                    isSpecClass = true;
                    curClass = class_temp;
                }
            }
            if (!isSpecClass)
                return ;

            std::vector<std::shared_ptr<Class>> driverClass;
            for (auto& ischema : moudle)
            {
                for (auto class_temp : ischema.second.classes)
                {
                    for (int index = 0; index < class_temp->m_base_classes.size(); ++index)
                    {
                        std::string& basename = class_temp->m_base_classes[index]->name;
                        if (basename == "JYE::" + specClassName)
                        {
                            driverClass.push_back(class_temp);
                        }
                    }
                }
            }

            Mustache::data class_def;
            genClassRenderData(curClass, class_def);
            class_defines.push_back(class_def);
            m_class_defines.push_back(class_def);

            Mustache::data driver_defines(Mustache::data::type::list);
            for (auto class_temp : driverClass)
            {
                if (!class_temp->shouldCompileFields())
                    continue;

                Mustache::data class_def;
                genClassRenderData(class_temp, class_def);

                // deal base class
                for (int index = 0; index < class_temp->m_base_classes.size(); ++index)
                {
                    auto include_file = m_get_include_func(class_temp->m_base_classes[index]->name);
                    if (!include_file.empty())
                    {
                        auto include_file_base = processFileName(include_file);
                        if (file_path != include_file_base)
                        {
                            include_headfiles.push_back(Mustache::data("headfile_name", Utils::makeRelativePath(m_root_path, include_file_base).string()));
                        }
                    }
                }

                class_def.set("driver_class_name", class_temp->getClassName());
                driver_defines.push_back(class_def);
            }

            muatache_data.set("class_defines", class_defines);
            muatache_data.set("class_driver_class_defines", driver_defines);
            muatache_data.set("include_headfiles", include_headfiles);
            std::string render_string = TemplateManager::getInstance()->renderByTemplate("commonSpecialClassGenFile", muatache_data);
            Utils::saveFile(render_string, file_path);

            m_include_headfiles.push_back(Mustache::data("headfile_name", Utils::makeRelativePath(m_root_path, file_path).string()));
        };

        for (auto& it : s_specClassNames)
        {
            processSpecClassFunc(it);
        }
        
        return 0;
    }
    void SpecialClassGenerator::finish()
    {
        Mustache::data mustache_data;
        mustache_data.set("class_defines", m_class_defines);
        mustache_data.set("include_headfiles", m_include_headfiles);

        std::string render_string = TemplateManager::getInstance()->renderByTemplate("allSpecialClassFile", mustache_data);
        Utils::saveFile(render_string, m_out_path + "/allSpecialClass.h");
    }

    SpecialClassGenerator::~SpecialClassGenerator() {}
} // namespace Generator