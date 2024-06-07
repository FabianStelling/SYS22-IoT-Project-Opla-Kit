#include <unity.h>
#include "ISensor.h"
#include "./../../lib/ActionTriggerer/src/ActionTriggerer.cpp"
#include "IAction.h"

// Mock sensor class for testing
class MockSensor : public ISensor {
public:
    MockSensor(float value) : value(value) {}
    float readSensorValue() override {
        return value;
    }
    void setValue(float newValue) {
        value = newValue;
    }
private:
    float value;
};

// Mock action class for testing
class MockAction : public IAction {
public:
    MockAction() : executed(false) {}
    void doAction() override {
        executed = true;
    }
    bool isExecuted() const {
        return executed;
    }
private:
    bool executed;
};

void setUp() {
    // set up code here, if needed
}

void tearDown() {
    // tear down code here, if needed
}

void test_MoistureSensor_readSensorValue() {
    MockSensor mockSensor(0.5);
    TEST_ASSERT_EQUAL_FLOAT(0.5, mockSensor.readSensorValue());
}

void test_ActionTriggerer_threshold_not_reached() {
    MockSensor mockSensor(0.6);
    MockAction mockAction;
    ActionTriggerer actionTriggerer(&mockSensor, &mockAction, 0.5);
    actionTriggerer.check();
    TEST_ASSERT_FALSE(mockAction.isExecuted());
}

void test_ActionTriggerer_threshold_reached() {
    MockSensor mockSensor(0.4);
    MockAction mockAction;
    ActionTriggerer actionTriggerer(&mockSensor, &mockAction, 0.5);
    actionTriggerer.check();
    TEST_ASSERT_TRUE(mockAction.isExecuted());
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_MoistureSensor_readSensorValue);
    RUN_TEST(test_ActionTriggerer_threshold_not_reached);
    RUN_TEST(test_ActionTriggerer_threshold_reached);
    UNITY_END();
}

void loop() {
    // empty loop
}

int main(int argc, char **argv) {
    setup();
    return 0;
}
