import de.bezier.data.sql.*;  
import processing.serial.*;   

MySQL msql;     

String[] a;
int end = 10;    
String serial;   
Serial port;     
int x = 0;

void setup() {
  String user     = "root";
  String pass     = "";
  String database = "datalogging";
  
  msql = new MySQL( this, "localhost", database, user, pass );
    
  port = new Serial(this, Serial.list()[0], 9600); 
  port.clear(); 
  serial = port.readStringUntil(end); 
  serial = null; 
}
void draw() 
{
  
  while (port.available() > 0) 
  { 
    
    serial = port.readStringUntil(end);
  }
    if (serial != null) 
    {  
      a = split(serial, ',');
      print("Gas: ");
      print(a[0]);
      println(" KJ/mol");
      
      print("Temp: ");
      print(a[1]);
      println(" Celsius");
      function();
    }
}

void function()
{
  if ( msql.connect() )
    {
        msql.query( "insert into gas_and_temp(Gas, Temperature) values("+a[0]+", "+a[1]+")" );
    }
    else
    {
       
    }
    msql.close(); 
}
