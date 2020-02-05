/*
   Copyright 2020 Raphael Beck

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../checknum.h"

static void null_test_success(void** state)
{
    (void)state;
}

static void test_zeros(void** state)
{
    assert_int_equal(checknum("0.00000", 0), 2);
    assert_int_equal(checknum("0", 0), 1);
    assert_int_equal(checknum("00", 0), 0);
    assert_int_equal(checknum("0  ", 0), 1);
    assert_int_equal(checknum("  0", 0), 1);
    assert_int_equal(checknum("  0  ", 0), 1);
    assert_int_equal(checknum(" 0123", 0), 0);
    assert_int_equal(checknum(".0 ", 0), 2);
    assert_int_equal(checknum(".00", 0), 2);
    assert_int_equal(checknum(" .   ", 0), 0);
    assert_int_equal(checknum("0.", 0), 2);
    assert_int_equal(checknum("+.", 0), 0);
    assert_int_equal(checknum("-.   ", 0), 0);
}

// --------------------------------------------------------------------------------------------------------------

int main(void)
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(test_zeros),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
