-module(dirty_scheduler).

-export([power/1]).
-export([power_dirty/1]).

power(Number) ->
    dirty_scheduler_nif:power(Number).

power_dirty(Number) ->
    dirty_scheduler_nif:power_dirty(Number).
