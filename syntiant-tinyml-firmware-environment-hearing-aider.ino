#include "src/syntiant.h"
#include <NDP.h>
#include <NDP_utils.h>
#include <Arduino.h>

/**
   @brief      Called when a inference matches 1 of the features

   @param[in]  event          The event
   @param[in]  confidence     The confidence
   @param[in]  anomaly_score  The anomaly score
*/

void on_classification_changed(const char *event, float confidence, float anomaly_score) {
  if ( (strcmp(event, "car_horn") == 0) || (strcmp(event, "ambulance_firetruck") == 0) ) {
    digitalWrite(LED_RED, HIGH);
    OUT_1_HIGH(); // set output to HIGH on GPIO 1
    delay(1500);
    OUT_1_LOW(); // set output to LOW on GPIO 1
  }

  else {
    digitalWrite(LED_RED, LOW);
    OUT_1_LOW(); // set output to LOW on GPIO 1
  }
}

void setup(void)
{
  syntiant_setup();
}

void loop(void)
{
  syntiant_loop();
}
