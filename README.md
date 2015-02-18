# dirty_scheduler

Don't forget to build your OTP with "--enable-dirty-schedulers" flag.
Check it with erlang:system_info(dirty_cpu_schedulers_online). It will return badarg if they are not enabled.

You can check if your call is being processed on a dirty scheduler with:
if(enif_is_on_dirty_scheduler(hp)) {
	//hp is ErlNifEnv
}

Since Erlang 17.03 enif_schedule_dirty_nif, enif_schedule_dirty_nif_finalizer and enif_dirty_nif_finalizer were removed (erl_nif.h).
More info: http://www.erlang.org/doc/man/erl_nif.html#enif_schedule_nif
