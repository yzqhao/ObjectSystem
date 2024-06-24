set (
	BUILD_LIST_COMMON
    ./System/ system_dir
    ./Meta/ meta_dir
    ./Math/ math_dir
    ./Core/ core_dir
    #./LuaScriptSystem/ lua_script_system_dir
    #./Application/ application_dir
	
    ./Test/TestModule/ test_testmodule_dir

	./Third/LuaVMLib/ lua_dir
	./Third/luasocket/ luasocket_dir
	./Third/lua-cjson/ lua_cjson_dir
	./Third/LuaBitOp-1.0.2/ lua_bit_dir
	./Third/luafilesystem/ luafilesystem_dir
	
	./Third/json11/ json11_lib
	
    ./Tools/meta_parser/ meta_parser_dir
)


set ( BUILD_LIST_COMMON
        ${BUILD_LIST_COMMON}
    )
	
set ( BUILD_LIST_WINDOWS
	${BUILD_LIST_COMMON}
)