-module(dirty_scheduler_nif).

-export([load/0, start/0]).
-export([power/1, power_dirty/1]).

%%%

load() ->
    {ok, Path0} = file:get_cwd(),
    Path = filename:join([Path0, "priv", "dirty_scheduler_drv"]),
    erlang:load_nif(Path, 0).

start() ->
    error(not_loaded).

power(_) ->
    error(not_loaded).

power_dirty(_) ->
    error(not_loaded).
