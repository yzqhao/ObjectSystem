#pragma once
#include "generator/generator.h"
namespace Generator
{
    class SpecialClassGenerator : public GeneratorInterface
    {
    public:
        SpecialClassGenerator() = delete;
        SpecialClassGenerator(std::string source_directory, std::function<std::string(std::string)> get_include_function);
        virtual int  generate(const std::string& path, const SchemaMoudle& schema, const std::unordered_map<std::string, SchemaMoudle>& moudle) override;
        virtual void finish() override;
        virtual ~SpecialClassGenerator() override;

    protected:
        virtual void prepareStatus(const std::string& path) override;
        virtual std::string processFileName(const std::string& path) override;

    private:
        Mustache::data m_class_defines{ Mustache::data::type::list };
        Mustache::data m_include_headfiles{ Mustache::data::type::list };
    };
} // namespace Generator
