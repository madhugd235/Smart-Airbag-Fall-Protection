#include <math.h>
#include <WiFi.h>
#include <EMailSender.h>
#include "Arduino.h"

/* Pin configuration */
const int x_out = 39;
const int y_out = 34;
const int z_out = 35;

int buzzer = 33;
int relay = 32;

/* WiFi credentials */
const char* ssid = "vivo 1907";
const char* password = "impanlee";

/* Email configuration */
EMailSender emailSend("madhugd6361@gmail.com", "grcmdnbewrksloam");

void sendmail()
{
  EMailSender::EMailMessage message;
  message.subject = "Alert!";
  message.message = "Fall Detected";

  EMailSender::Response resp = emailSend.send("impanab22@gmail.com", message);

  if (resp.status)
  {
    Serial.println("Mail Sent");
    delay(5000);
  }
  else
  {
    Serial.print("Error in sending mail, response code: ");
    Serial.println(resp.code);
    delay(5000);
  }

  Serial.println(resp.desc);
}

void setup()
{
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("WiFi connected!");

  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);

  delay(2000);
}

void loop()
{
  int x_adc_value, y_adc_value, z_adc_value;

  x_adc_value = analogRead(x_out);
  y_adc_value = analogRead(y_out);
  z_adc_value = analogRead(z_out);

  Serial.print("x = ");
  Serial.print(x_adc_value);
  Serial.print("\t");

  Serial.print("y = ");
  Serial.print(y_adc_value);
  Serial.print("\t");

  Serial.print("z = ");
  Serial.print(z_adc_value);
  Serial.println("");

  delay(1000);

  if ((x_adc_value > 1800 && x_adc_value < 2000) &&
      (y_adc_value > 1800 && y_adc_value < 2000))
  {
    Serial.println("NO FALL");
    digitalWrite(relay, LOW);
  }
  else
  {
    Serial.println("FALL DETECTED");
    digitalWrite(relay, HIGH);
    tone(buzzer, 2000);
    sendmail();
    noTone(buzzer);
  }
}
