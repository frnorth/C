#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int hello(lua_State *L)
{
	lua_pushstring(L, "Hello World!");

	return 1;
}

int luaopen_hello(lua_State *L)
{
	lua_register(L, "hello", hello);
	return 1;
}
