//
// Created by Michael Lipinski on 17/01/2018.
//

#include "./stub.h"
#include "example/stub.h"

START_TEST (test_parser_subtract_if_a_gt_b)
{
    int result = stubExampleFunction(5, 2);
    ck_assert_uint_eq(result, 3);
}
END_TEST

START_TEST (test_parser_add_if_b_gt_a)
    {
        int result = stubExampleFunction(1, 2);
        ck_assert_uint_eq(result, 3);
    }
END_TEST

START_TEST (test_parser_add_works_if_negative_args)
    {
        int result = stubExampleFunction(-1, -5);
        ck_assert_uint_eq(result, 4);

        result = stubExampleFunction(10, -5);
        ck_assert_uint_eq(result, 15);
    }
END_TEST

void fillSuite_example_stub(Suite* suite) {
    TCase *tcase = tcase_create("stub tests");
    tcase_add_test(tcase, test_parser_subtract_if_a_gt_b);
    tcase_add_test(tcase, test_parser_add_if_b_gt_a);
    tcase_add_test(tcase, test_parser_add_works_if_negative_args);
    suite_add_tcase(suite, tcase);
}