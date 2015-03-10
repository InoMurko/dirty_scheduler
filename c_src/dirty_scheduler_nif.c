#include <math.h>
#include <erl_nif.h>

typedef ErlNifEnv 		nif_heap_t;
typedef ERL_NIF_TERM 		nif_term_t;
typedef ErlNifFunc 		nif_func_t;

#ifdef ERL_NIF_DIRTY_SCHEDULER_SUPPORT
#warning "Dirty scheduler functions are enabled"
#else
#warning "Dirty scheduler functions are not enabled"
#endif

static nif_term_t
power(nif_heap_t *hp, int argc, const nif_term_t argv[])
{
	int value;
    enif_get_int(hp, argv[0], &value);
	return enif_make_int(hp, pow(value,2));
}

#ifdef ERL_NIF_DIRTY_SCHEDULER_SUPPORT
static nif_term_t
power_dirty(nif_heap_t *hp, int argc, const nif_term_t argv[])
{
	int flags = ERL_NIF_DIRTY_JOB_CPU_BOUND;
	return enif_schedule_nif(hp, "power", flags, power, argc, argv);
}
#else
static nif_term_t
power_dirty(nif_heap_t *hp, int argc, const nif_term_t argv[])
{
	nif_term_t 		tag;
	tag = enif_make_atom(hp, "unsupported_dirty_scheduler");
	return (tag);
}
#endif

static nif_func_t exports[] = {
	{"power", 1, power},
	{"power_dirty", 1, power_dirty}
};

ERL_NIF_INIT(dirty_scheduler_nif, exports, NULL, NULL, NULL, NULL);
