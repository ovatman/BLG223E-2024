#include <stdlib.h>
#include "munit.h"
#include "expanding_array.h"

static void* test_setup(const MunitParameter params[], void* user_data) {
    int init_cap = atoi(munit_parameters_get(params, "init_cap"));
    ExpandingArray* ea = (ExpandingArray*) calloc(1, sizeof(ExpandingArray));
    init_expanding_array(ea, init_cap);
    return ea;
}

static void* test_setup_with_elems(const MunitParameter params[], void* user_data) {
    int init_cap = atoi(munit_parameters_get(params, "init_cap"));
    int init_elem = atoi(munit_parameters_get(params, "init_elem"));

    ExpandingArray* ea = (ExpandingArray*) calloc(1, sizeof(ExpandingArray));
    init_expanding_array(ea, init_cap);
    
    for(int i=0; i<init_elem; i++)
        add_to_expanding_array(ea, init_elem - i);
    
    return ea;
}

static void test_tear_down(void* fixture) {
    destroy_expanding_array((ExpandingArray*) fixture);
}


static MunitResult test_init(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;
    int init_cap = atoi(munit_parameters_get(params, "init_cap"));

    munit_assert_not_null(ea->array);
    munit_assert_int(ea->size, ==, 0);
    munit_assert_int(ea->capacity, ==, init_cap);
    munit_assert_int(ea->delta, ==, 10);
    return MUNIT_OK;
}

static MunitResult test_add(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;
    int init_cap = atoi(munit_parameters_get(params, "init_cap"));
    int init_elem = atoi(munit_parameters_get(params, "init_elem"));

    for(int i=0; i<init_elem; i++)
        munit_assert_int(ea->array[i], ==, init_elem - i);

    munit_assert_int(ea->size, ==, init_elem);

    int expected_cap = ea->size > init_cap ? init_cap + (((ea->size - init_cap) / ea->delta)+1) * ea->delta : init_cap;
    munit_assert_int(ea->capacity, ==, expected_cap);    

    return MUNIT_OK;
}

static MunitResult test_read_from(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;
    int init_elem = atoi(munit_parameters_get(params, "init_elem"));

    for(int i=0; i<init_elem; i++)
        munit_assert_int(read_from_expanding_array(ea, i), ==, init_elem - i);

    return MUNIT_OK;
}


static MunitResult test_replace(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;

    replace_in_expanding_array(ea, 100, 3);

    munit_assert_int(ea->array[3], ==, 100);

    return MUNIT_OK;
}


static MunitResult test_insert(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;
    int init_elem = atoi(munit_parameters_get(params, "init_elem"));

    int cap_before = ea->capacity;

    insert_into_expanding_array(ea, 50, 1);  //we also test expansion

    munit_assert_int(ea->array[1], ==, 50);
    munit_assert_int(ea->size, ==, init_elem + 1);

    int expected_cap = ea->size > cap_before ? cap_before + ea->delta : cap_before;
    munit_assert_int(ea->capacity, ==, expected_cap);

    return MUNIT_OK;
}

static MunitResult test_remove_shrink(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;
    int init_cap = atoi(munit_parameters_get(params, "init_cap"));
    int init_elem = atoi(munit_parameters_get(params, "init_elem"));

    int cap_before = ea->capacity;
    int first_before = ea->array[1];

    remove_from_expanding_array(ea, 0);

    munit_assert_int(ea->array[0], ==, first_before);
    munit_assert_int(ea->size, ==, init_elem - 1);
    int expected_cap = init_elem == cap_before && cap_before - ea->delta > 0 ? cap_before - ea->delta : cap_before;
    munit_assert_int(ea->capacity, ==, expected_cap);

    return MUNIT_OK;
}

static MunitResult test_destroy(const MunitParameter params[], void* data) {
    ExpandingArray* ea = (ExpandingArray*) data;

    destroy_expanding_array(ea);

    munit_assert_null(ea->array);
    munit_assert_int(ea->size, ==, -1);
    munit_assert_int(ea->capacity, ==, -1);
    munit_assert_int(ea->delta, ==, -1);

    return MUNIT_OK;
}

static char* init_capacity_params[] = {
  (char*) "10", NULL
};

static char* init_num_of_elements_params[] = {
  (char*) "5", (char*) "10", (char*) "11", (char*) "15", NULL
};

static MunitParameterEnum test_params[] = {
  { (char*) "init_cap", init_capacity_params },
  { (char*) "init_elem", init_num_of_elements_params },
  { NULL, NULL },
};

static MunitTest test_suite_tests[] = {
  { (char*) "/expanding_array/init", test_init, test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, test_params},
  { (char*) "/expanding_array/add", test_add, test_setup_with_elems, test_tear_down, MUNIT_TEST_OPTION_NONE, test_params},
  { (char*) "/expanding_array/read_from", test_read_from, test_setup_with_elems, test_tear_down, MUNIT_TEST_OPTION_NONE, test_params},
  { (char*) "/expanding_array/replace", test_replace, test_setup_with_elems, test_tear_down, MUNIT_TEST_OPTION_NONE, test_params},
  { (char*) "/expanding_array/remove_shrink", test_replace, test_setup_with_elems, test_tear_down, MUNIT_TEST_OPTION_NONE, test_params},
  { (char*) "/expanding_array/destroy", test_destroy, test_setup_with_elems, NULL, MUNIT_TEST_OPTION_NONE, test_params},
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  (char*) "",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};