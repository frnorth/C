#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int sum (lua_State *L) {
	int n = lua_gettop(L);    /* number of arguments */
	lua_Number sum = 0.0;
	int i;

	for (i = 1; i <= n; i++) {
		if (!lua_isnumber(L, i)) {
		lua_pushliteral(L, "incorrect argument");
		lua_error(L);
		}
		sum += lua_tonumber(L, i);
	}
	lua_pushstring(L, "average: ");        /* first result */
	lua_pushnumber(L, sum/n);        /* second result */
	lua_pushstring(L, "\nsum: ");        /* third result */
	lua_pushnumber(L, sum);         /* fourth result */
	return 4;                   /* number of results */
}

int luaopen_sum(lua_State *L)
{
	lua_register(L, "sum", sum);
	return 1;
}
