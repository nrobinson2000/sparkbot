/*Paste this into the spark.io web IDE
This firmware uses the Photon's API abilites to send a PushBullet notification when on of the buttons is pressed.
To use this firmware, you must have created a PushBullet account and found your access token.
*/

TCPClient client;
const char * server ="https://api.pushbullet.com";
const char * token = "YOUR_ACCESS_TOKEN"; //Put your access token here
const char * title = "Hello World!";
const char * body = "This is SparkBot speaking.";

void setup() {
pinMode(D7, INPUT);
}

void pushbullet()
{
    if (client.connect(server, 80))
  {
    client.println("POST /v2/pushes/ HTTP/1.0");
    client.println("Host: ");
    client.print(server);
    client.println("Authorization: ");
    client.print(token);
    client.println("Content-Type: application/json");
    client.println("User-Agent: Spark");
    client.println("Content-Length: ");
    client.print(strlen(title)+strlen(body)+43);
    client.println();
    client.print('{"type": "note", "title": ');
    client.print(title);
    client.print(', "body": "');
    client.print(body);
    client.print('"}');
    client.println();
    client.flush();
  }
}
void loop() {
    if (digitalRead(D7) == HIGH)
    {
        pushbullet();
    }
}
