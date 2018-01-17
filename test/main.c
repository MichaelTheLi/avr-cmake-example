//
// Created by Michael Lipinski on 15/01/2018.
//

#include <check.h>

#include "./example/stub.h"

Suite* str_suite (void) {
    Suite *suite = suite_create("Main suite");

    fillSuite_example_stub(suite);

    return suite;
}

int main (int argc, char *argv[]) {
    int number_failed;

    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}