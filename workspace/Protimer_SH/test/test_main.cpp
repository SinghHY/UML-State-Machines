#include <Arduino.h>
#include <unity.h>

String STR_TO_TEST;

void setUp(void) {
    // set stuff up here
    STR_TO_TEST = "Hello, world!";
}

void tearDown(void) {
    // clean stuff up here
    STR_TO_TEST = "";
}