<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ArduinoNanoV30">
<packages>
<package name="ARDUINO_NANO">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;
&lt;p&gt;The Nano was designed and is being produced by Gravitech.&lt;br&gt;

&lt;a href="http://www.gravitech.us/arna30wiatp.html"&gt;Gravitech Arduino Nano V3.0&lt;/a&gt;&lt;/p&gt;</description>
<hole x="-22.86" y="-7.62" drill="1.778"/>
<pad name="1" x="-20.32" y="-7.62" drill="0.8" shape="square"/>
<pad name="2" x="-17.78" y="-7.62" drill="0.8"/>
<pad name="3" x="-15.24" y="-7.62" drill="0.8"/>
<pad name="4" x="-12.7" y="-7.62" drill="0.8"/>
<pad name="5" x="-10.16" y="-7.62" drill="0.8"/>
<pad name="6" x="-7.62" y="-7.62" drill="0.8"/>
<pad name="7" x="-5.08" y="-7.62" drill="0.8"/>
<pad name="8" x="-2.54" y="-7.62" drill="0.8"/>
<pad name="9" x="0" y="-7.62" drill="0.8"/>
<pad name="10" x="2.54" y="-7.62" drill="0.8"/>
<pad name="11" x="5.08" y="-7.62" drill="0.8"/>
<pad name="12" x="7.62" y="-7.62" drill="0.8"/>
<pad name="13" x="10.16" y="-7.62" drill="0.8"/>
<pad name="14" x="12.7" y="-7.62" drill="0.8"/>
<pad name="15" x="15.24" y="-7.62" drill="0.8"/>
<pad name="16" x="15.24" y="7.62" drill="0.8"/>
<pad name="17" x="12.7" y="7.62" drill="0.8"/>
<pad name="18" x="10.16" y="7.62" drill="0.8"/>
<pad name="19" x="7.62" y="7.62" drill="0.8"/>
<pad name="20" x="5.08" y="7.62" drill="0.8"/>
<pad name="21" x="2.54" y="7.62" drill="0.8"/>
<pad name="22" x="0" y="7.62" drill="0.8"/>
<pad name="23" x="-2.54" y="7.62" drill="0.8"/>
<pad name="24" x="-5.08" y="7.62" drill="0.8"/>
<pad name="25" x="-7.62" y="7.62" drill="0.8"/>
<pad name="26" x="-10.16" y="7.62" drill="0.8"/>
<pad name="27" x="-12.7" y="7.62" drill="0.8"/>
<pad name="28" x="-15.24" y="7.62" drill="0.8"/>
<pad name="29" x="-17.78" y="7.62" drill="0.8"/>
<pad name="30" x="-20.32" y="7.62" drill="0.8"/>
<hole x="-22.86" y="7.62" drill="1.778"/>
<hole x="17.78" y="7.62" drill="1.778"/>
<hole x="17.78" y="-7.62" drill="1.778"/>
<wire x1="-24.13" y1="8.89" x2="19.05" y2="8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="8.89" x2="19.05" y2="3.81" width="0.127" layer="21"/>
<wire x1="19.05" y1="3.81" x2="19.05" y2="-3.81" width="0.127" layer="21"/>
<wire x1="19.05" y1="-3.81" x2="19.05" y2="-8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="-8.89" x2="-24.13" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="-8.89" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-24.13" y2="8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-25.4" y2="2.54" width="0.127" layer="21"/>
<wire x1="-25.4" y1="2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-19.05" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="2.54" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<text x="-17.78" y="0" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="-17.78" y="-2.54" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<circle x="0" y="0" radius="1.79605" width="0.127" layer="21"/>
<text x="3.81" y="-1.27" size="0.8128" layer="21" font="vector" rot="R90">Reset</text>
<text x="-20.32" y="-6.35" size="1.016" layer="21" font="vector">1</text>
<text x="-17.78" y="3.81" size="0.6096" layer="21" font="vector" rot="R180">Mini-B USB</text>
<wire x1="19.05" y1="3.81" x2="13.97" y2="3.81" width="0.127" layer="21"/>
<wire x1="13.97" y1="3.81" x2="13.97" y2="-3.81" width="0.127" layer="21"/>
<wire x1="13.97" y1="-3.81" x2="19.05" y2="-3.81" width="0.127" layer="21"/>
<circle x="17.78" y="-2.54" radius="0.8" width="0.127" layer="21"/>
<circle x="17.78" y="0" radius="0.8" width="0.127" layer="21"/>
<circle x="17.78" y="2.54" radius="0.8" width="0.127" layer="21"/>
<circle x="15.24" y="2.54" radius="0.8" width="0.127" layer="21"/>
<circle x="17.78" y="0" radius="0.8" width="0.127" layer="21"/>
<circle x="15.24" y="0" radius="0.8" width="0.127" layer="21"/>
<circle x="15.24" y="-2.54" radius="0.8" width="0.127" layer="21"/>
<text x="12.7" y="1.27" size="0.8128" layer="21" font="vector" rot="SR270">ICSP</text>
</package>
</packages>
<symbols>
<symbol name="ARDUINO_NANO">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;&lt;br&gt;

&lt;b&gt;Overview:&lt;/b&gt;&lt;br&gt;

The Arduino Nano is a small, complete, and breadboard-friendly board based on the ATmega328 (Arduino Nano 3.x) or ATmega168 (Arduino Nano 2.x). It has more or less the same functionality of the Arduino Duemilanove, but in a different package. It lacks only a DC power jack, and works with a Mini-B USB cable instead of a standard one.&lt;br&gt;
The Nano was designed and is being produced by Gravitech.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Specifications:&lt;/b&gt;
&lt;table border="1" style="width:auto"&gt;
  &lt;tr&gt;
    &lt;td&gt;Microcontroller&lt;/td&gt;
    &lt;td&gt;Atmel ATmega168 or ATmega328&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Operating Voltage (logic level)&lt;/td&gt;
    &lt;td&gt;5 V&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (recommended)&lt;/td&gt;
    &lt;td&gt;7-12 V&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (limits)&lt;/td&gt;
    &lt;td&gt;6-20 V&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Digital I/O Pins&lt;/td&gt;
    &lt;td&gt;14 (of which 6 provide PWM output)&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Analog Input Pins&lt;/td&gt;
    &lt;td&gt;8&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;DC Current per I/O Pin&lt;/td&gt;
    &lt;td&gt;40 mA&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Flash Memory&lt;/td&gt;
    &lt;td&gt;16 KB (ATmega168) or 32 KB (ATmega328) of which 2 KB used by bootloader&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;SRAM&lt;/td&gt;
    &lt;td&gt;1 KB (ATmega168) or 2 KB (ATmega328)&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;EEPROM&lt;/td&gt;
    &lt;td&gt;512 bytes (ATmega168) or 1 KB (ATmega328)&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Clock Speed&lt;/td&gt;
    &lt;td&gt;16 MHz&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Dimensions&lt;/td&gt;
    &lt;td&gt;0.73" x 1.70"&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Length&lt;/td&gt;
    &lt;td&gt;45 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Width&lt;/td&gt;
    &lt;td&gt;18 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Weigth&lt;/td&gt;
    &lt;td&gt;5 g&lt;/td&gt;
  &lt;/tr&gt;
&lt;/table&gt;
&lt;br&gt;&lt;br&gt;

&lt;b&gt;Power:&lt;/b&gt;&lt;br&gt;

The Arduino Nano can be powered via the Mini-B USB connection, 6-20V unregulated external power supply (pin 30), or 5V regulated external power supply (pin 27).&lt;br&gt;
The power source is automatically selected to the highest voltage source.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Memory:&lt;/b&gt;&lt;br&gt;

The ATmega168 has 16 KB of flash memory for storing code (of which 2 KB is used for the bootloader); the ATmega328 has 32 KB, (also with 2 KB used for the bootloader).&lt;br&gt;
The ATmega168 has 1 KB of SRAM and 512 bytes of EEPROM (which can be read and written with the EEPROM library); the ATmega328 has 2 KB of SRAM and 1 KB of EEPROM.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Input and Output:&lt;/b&gt;&lt;br&gt;

Each of the 14 digital pins on the Nano can be used as an input or output, using pinMode(), digitalWrite(), and digitalRead() functions.&lt;br&gt;
They operate at 5 volts.&lt;br&gt;
Each pin can provide or receive a maximum of 40 mA and has an internal pull-up resistor (disconnected by default) of 20-50 kOhms. In addition, some pins have specialized functions.&lt;br&gt;&lt;br&gt;

&lt;a href="https://www.arduino.cc/en/Main/ArduinoBoardNano"&gt;Visit Arduino - ArduinoBoardNano&lt;/a&gt;</description>
<wire x1="-15.24" y1="-25.4" x2="-15.24" y2="15.24" width="0.254" layer="94"/>
<wire x1="-15.24" y1="15.24" x2="-5.08" y2="15.24" width="0.254" layer="94"/>
<wire x1="-5.08" y1="15.24" x2="5.08" y2="15.24" width="0.254" layer="94"/>
<wire x1="5.08" y1="15.24" x2="15.24" y2="15.24" width="0.254" layer="94"/>
<wire x1="15.24" y1="15.24" x2="15.24" y2="-25.4" width="0.254" layer="94"/>
<wire x1="15.24" y1="-25.4" x2="-15.24" y2="-25.4" width="0.254" layer="94"/>
<pin name="TX1" x="-20.32" y="12.7" length="middle"/>
<pin name="RX0" x="-20.32" y="10.16" length="middle"/>
<pin name="!RESET@1" x="-20.32" y="7.62" length="middle" direction="in" function="dot"/>
<pin name="GND@1" x="-20.32" y="5.08" length="middle" direction="pwr"/>
<pin name="D2" x="-20.32" y="2.54" length="middle"/>
<pin name="D3" x="-20.32" y="0" length="middle"/>
<pin name="D4" x="-20.32" y="-2.54" length="middle"/>
<pin name="D5" x="-20.32" y="-5.08" length="middle"/>
<pin name="D6" x="-20.32" y="-7.62" length="middle"/>
<pin name="D7" x="-20.32" y="-10.16" length="middle"/>
<pin name="D8" x="-20.32" y="-12.7" length="middle"/>
<pin name="D9" x="-20.32" y="-15.24" length="middle"/>
<pin name="D10" x="-20.32" y="-17.78" length="middle"/>
<pin name="D11" x="-20.32" y="-20.32" length="middle"/>
<pin name="D12" x="-20.32" y="-22.86" length="middle"/>
<pin name="D13" x="20.32" y="-22.86" length="middle" rot="R180"/>
<pin name="3V3" x="20.32" y="-20.32" length="middle" direction="out" rot="R180"/>
<pin name="AREF" x="20.32" y="-17.78" length="middle" direction="in" rot="R180"/>
<pin name="A0" x="20.32" y="-15.24" length="middle" rot="R180"/>
<pin name="A1" x="20.32" y="-12.7" length="middle" rot="R180"/>
<pin name="A2" x="20.32" y="-10.16" length="middle" rot="R180"/>
<pin name="A3" x="20.32" y="-7.62" length="middle" rot="R180"/>
<pin name="A4" x="20.32" y="-5.08" length="middle" rot="R180"/>
<pin name="A5" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="A6" x="20.32" y="0" length="middle" rot="R180"/>
<pin name="A7" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="5V" x="20.32" y="5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="!RESET@2" x="20.32" y="7.62" length="middle" direction="in" function="dot" rot="R180"/>
<pin name="GND@2" x="20.32" y="10.16" length="middle" direction="pwr" rot="R180"/>
<pin name="VIN" x="20.32" y="12.7" length="middle" direction="pwr" rot="R180"/>
<wire x1="2.54" y1="-20.32" x2="-2.54" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-20.32" x2="-2.54" y2="-26.67" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-26.67" x2="2.54" y2="-26.67" width="0.254" layer="94"/>
<wire x1="2.54" y1="-26.67" x2="2.54" y2="-20.32" width="0.254" layer="94"/>
<text x="-2.54" y="-17.78" size="1.4224" layer="94" font="vector">Mini-B
 USB</text>
<circle x="0" y="0" radius="2.54" width="0.254" layer="94"/>
<text x="-2.54" y="-7.62" size="1.4224" layer="94" font="vector">RESET
BUTTON</text>
<text x="-15.24" y="-30.48" size="1.778" layer="95">&gt;NAME</text>
<text x="-15.24" y="-33.02" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-5.08" y1="15.24" x2="-5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="10.16" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="5.08" y2="15.24" width="0.254" layer="94"/>
<text x="-2.54" y="7.62" size="1.6764" layer="94" font="vector">ICSP</text>
<circle x="-2.54" y="11.43" radius="0.762" width="0.254" layer="94"/>
<circle x="0" y="13.97" radius="0.762" width="0.254" layer="94"/>
<circle x="2.54" y="13.97" radius="0.762" width="0.254" layer="94"/>
<circle x="-2.54" y="13.97" radius="0.762" width="0.254" layer="94"/>
<circle x="2.54" y="11.43" radius="0.762" width="0.254" layer="94"/>
<circle x="0" y="11.43" radius="0.762" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ARDUINO_NANO" prefix="ARDUINO_NANO" uservalue="yes">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;&lt;br&gt;

&lt;b&gt;Overview:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The Arduino Nano is a small, complete, and breadboard-friendly board based on the ATmega328 (Arduino Nano 3.x) or ATmega168 (Arduino Nano 2.x). &lt;br&gt;It has more or less the same functionality of the Arduino Duemilanove, but in a different package.&lt;br&gt;
It lacks only a DC power jack, and works with a Mini-B USB cable instead of a standard one.&lt;br&gt;
The Nano was designed and is being produced by Gravitech.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Specifications:&lt;/b&gt;
&lt;table border="1" style="width:auto"&gt;
  &lt;tr&gt;
    &lt;td&gt;Microcontroller&lt;/td&gt;
    &lt;td&gt;Atmel ATmega168 or ATmega328&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Operating Voltage (logic level)&lt;/td&gt;
    &lt;td&gt;5 V&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (recommended)&lt;/td&gt;
    &lt;td&gt;7-12 V&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (limits)&lt;/td&gt;
    &lt;td&gt;6-20 V&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Digital I/O Pins&lt;/td&gt;
    &lt;td&gt;14 (of which 6 provide PWM output)&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Analog Input Pins&lt;/td&gt;
    &lt;td&gt;8&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;DC Current per I/O Pin&lt;/td&gt;
    &lt;td&gt;40 mA&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Flash Memory&lt;/td&gt;
    &lt;td&gt;16 KB (ATmega168) or 32 KB (ATmega328) of which 2 KB used by bootloader&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;SRAM&lt;/td&gt;
    &lt;td&gt;1 KB (ATmega168) or 2 KB (ATmega328)&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;EEPROM&lt;/td&gt;
    &lt;td&gt;512 bytes (ATmega168) or 1 KB (ATmega328)&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Clock Speed&lt;/td&gt;
    &lt;td&gt;16 MHz&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Dimensions&lt;/td&gt;
    &lt;td&gt;0.73" x 1.70"&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Length&lt;/td&gt;
    &lt;td&gt;45 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Width&lt;/td&gt;
    &lt;td&gt;18 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Weigth&lt;/td&gt;
    &lt;td&gt;5 g&lt;/td&gt;
  &lt;/tr&gt;
&lt;/table&gt;
&lt;br&gt;&lt;br&gt;

&lt;b&gt;Power:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The Arduino Nano can be powered via the Mini-B USB connection, 6-20V unregulated external power supply (pin 30), or 5V regulated external power supply (pin 27).&lt;br&gt;
The power source is automatically selected to the highest voltage source.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Memory:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The ATmega168 has 16 KB of flash memory for storing code (of which 2 KB is used for the bootloader); the ATmega328 has 32 KB, (also with 2 KB used for the bootloader).&lt;br&gt;
The ATmega168 has 1 KB of SRAM and 512 bytes of EEPROM (which can be read and written with the EEPROM library); the ATmega328 has 2 KB of SRAM and 1 KB of EEPROM.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Input and Output:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;Each of the 14 digital pins on the Nano can be used as an input or output, using pinMode(), digitalWrite(), and digitalRead() functions.&lt;br&gt;
They operate at 5 volts.&lt;br&gt;
Each pin can provide or receive a maximum of 40 mA and has an internal pull-up resistor (disconnected by default) of 20-50 kOhms. In addition, some pins have specialized functions.&lt;/p&gt;&lt;br&gt;

&lt;a href="https://www.arduino.cc/en/Main/ArduinoBoardNano"&gt;Visit Arduino - ArduinoBoardNano&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="ARDUINO_NANO" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ARDUINO_NANO">
<connects>
<connect gate="G$1" pin="!RESET@1" pad="18"/>
<connect gate="G$1" pin="!RESET@2" pad="13"/>
<connect gate="G$1" pin="3V3" pad="2"/>
<connect gate="G$1" pin="5V" pad="12"/>
<connect gate="G$1" pin="A0" pad="4"/>
<connect gate="G$1" pin="A1" pad="5"/>
<connect gate="G$1" pin="A2" pad="6"/>
<connect gate="G$1" pin="A3" pad="7"/>
<connect gate="G$1" pin="A4" pad="8"/>
<connect gate="G$1" pin="A5" pad="9"/>
<connect gate="G$1" pin="A6" pad="10"/>
<connect gate="G$1" pin="A7" pad="11"/>
<connect gate="G$1" pin="AREF" pad="3"/>
<connect gate="G$1" pin="D10" pad="28"/>
<connect gate="G$1" pin="D11" pad="29"/>
<connect gate="G$1" pin="D12" pad="30"/>
<connect gate="G$1" pin="D13" pad="1"/>
<connect gate="G$1" pin="D2" pad="20"/>
<connect gate="G$1" pin="D3" pad="21"/>
<connect gate="G$1" pin="D4" pad="22"/>
<connect gate="G$1" pin="D5" pad="23"/>
<connect gate="G$1" pin="D6" pad="24"/>
<connect gate="G$1" pin="D7" pad="25"/>
<connect gate="G$1" pin="D8" pad="26"/>
<connect gate="G$1" pin="D9" pad="27"/>
<connect gate="G$1" pin="GND@1" pad="19"/>
<connect gate="G$1" pin="GND@2" pad="14"/>
<connect gate="G$1" pin="RX0" pad="17"/>
<connect gate="G$1" pin="TX1" pad="16"/>
<connect gate="G$1" pin="VIN" pad="15"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="st-microelectronics" urn="urn:adsk.eagle:library:368">
<description>&lt;b&gt;ST Microelectronics Devices&lt;/b&gt;&lt;p&gt;
Microcontrollers,  I2C components, linear devices&lt;p&gt;
http://www.st.com&lt;p&gt;
&lt;i&gt;Include st-microelectronics-2.lbr, st-microelectronics-3.lbr.&lt;p&gt;&lt;/i&gt;

&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DIL16" urn="urn:adsk.eagle:footprint:26704/1" library_version="6">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="10.16" y1="2.921" x2="-10.16" y2="2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="10.16" y1="2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="2.921" x2="-10.16" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="-10.16" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.016" x2="-10.16" y2="-1.016" width="0.1524" layer="21" curve="-180"/>
<pad name="1" x="-8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="9" x="8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="10" x="6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="11" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="12" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="13" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="14" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="15" x="-6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="16" x="-8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-10.541" y="-2.921" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-7.493" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="DIL16" urn="urn:adsk.eagle:package:26820/1" type="box" library_version="6">
<description>Dual In Line Package</description>
<packageinstances>
<packageinstance name="DIL16"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="L293D" urn="urn:adsk.eagle:symbol:26701/1" library_version="6">
<wire x1="-10.16" y1="20.32" x2="-10.16" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-20.32" x2="10.16" y2="-20.32" width="0.254" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="10.16" y2="20.32" width="0.254" layer="94"/>
<wire x1="10.16" y1="20.32" x2="-10.16" y2="20.32" width="0.254" layer="94"/>
<text x="-10.16" y="21.336" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-22.86" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1-2EN" x="-15.24" y="17.78" length="middle" direction="in"/>
<pin name="1A" x="-15.24" y="12.7" length="middle" direction="in"/>
<pin name="1Y" x="-15.24" y="7.62" length="middle" direction="out"/>
<pin name="GND1" x="-15.24" y="2.54" length="middle" direction="pwr"/>
<pin name="GND2" x="-15.24" y="-2.54" length="middle" direction="pwr"/>
<pin name="2Y" x="-15.24" y="-7.62" length="middle" direction="out"/>
<pin name="2A" x="-15.24" y="-12.7" length="middle" direction="in"/>
<pin name="VCC2" x="-15.24" y="-17.78" length="middle" direction="pwr"/>
<pin name="VCC1" x="15.24" y="17.78" length="middle" direction="pwr" rot="R180"/>
<pin name="4A" x="15.24" y="12.7" length="middle" direction="in" rot="R180"/>
<pin name="4Y" x="15.24" y="7.62" length="middle" direction="out" rot="R180"/>
<pin name="GND3" x="15.24" y="2.54" length="middle" direction="pwr" rot="R180"/>
<pin name="GND4" x="15.24" y="-2.54" length="middle" direction="pwr" rot="R180"/>
<pin name="3Y" x="15.24" y="-7.62" length="middle" direction="out" rot="R180"/>
<pin name="3A" x="15.24" y="-12.7" length="middle" direction="in" rot="R180"/>
<pin name="3-4EN" x="15.24" y="-17.78" length="middle" direction="in" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="L293D" urn="urn:adsk.eagle:component:26880/3" prefix="IC" library_version="6">
<description>&lt;b&gt;PUSH-PULL 4 CHANNEL DRIVER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="L293D" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIL16">
<connects>
<connect gate="G$1" pin="1-2EN" pad="1"/>
<connect gate="G$1" pin="1A" pad="2"/>
<connect gate="G$1" pin="1Y" pad="3"/>
<connect gate="G$1" pin="2A" pad="7"/>
<connect gate="G$1" pin="2Y" pad="6"/>
<connect gate="G$1" pin="3-4EN" pad="9"/>
<connect gate="G$1" pin="3A" pad="10"/>
<connect gate="G$1" pin="3Y" pad="11"/>
<connect gate="G$1" pin="4A" pad="15"/>
<connect gate="G$1" pin="4Y" pad="14"/>
<connect gate="G$1" pin="GND1" pad="4"/>
<connect gate="G$1" pin="GND2" pad="5"/>
<connect gate="G$1" pin="GND3" pad="13"/>
<connect gate="G$1" pin="GND4" pad="12"/>
<connect gate="G$1" pin="VCC1" pad="16"/>
<connect gate="G$1" pin="VCC2" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:26820/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="L293D" constant="no"/>
<attribute name="OC_FARNELL" value="9589619" constant="no"/>
<attribute name="OC_NEWARK" value="56P8249" constant="no"/>
<attribute name="POPULARITY" value="16" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="amass">
<description>&lt;b&gt;AMASS PCB type connector&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by Suzaku Lab. Ltd. &lt;a href="mailto:support@suzakugiken.jp"&gt;support@suzakugiken.jp&lt;/a&gt;&lt;/author&gt;
&lt;p&gt;This is an unofficial library. If you notice a mistake, please contact the author.&lt;/p&gt;

&lt;p&gt;We, &lt;a href="https://suzakugiken.jp/"&gt;Suzaku Lab. Ltd.&lt;/a&gt;, are the authorized distributor in Japan.&lt;/p&gt;</description>
<packages>
<package name="XT30PW-F">
<description>AMASS XT30PW female type connector</description>
<pad name="-" x="-2.5" y="0" drill="1.8"/>
<pad name="+" x="2.5" y="0" drill="1.8"/>
<pad name="P$3" x="-5.5" y="5" drill="1.1"/>
<pad name="P$4" x="5.5" y="5" drill="1.1"/>
<wire x1="2" y1="5" x2="3" y2="5" width="0.127" layer="21"/>
<wire x1="2.5" y1="4.5" x2="2.5" y2="5.5" width="0.127" layer="21"/>
<wire x1="-6.65" y1="6" x2="-4.95" y2="6" width="0.127" layer="21"/>
<wire x1="-4.95" y1="6" x2="4.95" y2="6" width="0.127" layer="21"/>
<wire x1="4.95" y1="6" x2="6.65" y2="6" width="0.127" layer="21"/>
<wire x1="-6.65" y1="4" x2="-3.75" y2="4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="4" x2="-1.25" y2="4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="4" x2="6.65" y2="4" width="0.127" layer="21"/>
<wire x1="-6.65" y1="6" x2="-6.65" y2="4" width="0.127" layer="21"/>
<wire x1="6.65" y1="6" x2="6.65" y2="4" width="0.127" layer="21"/>
<wire x1="4.95" y1="8" x2="0.5" y2="8" width="0.127" layer="21"/>
<wire x1="0.5" y1="8" x2="0.4" y2="8" width="0.127" layer="21"/>
<wire x1="0.4" y1="8" x2="0.3" y2="8" width="0.127" layer="21"/>
<wire x1="0.3" y1="8" x2="0.2" y2="8" width="0.127" layer="21"/>
<wire x1="0.2" y1="8" x2="0.1" y2="8" width="0.127" layer="21"/>
<wire x1="0.1" y1="8" x2="0" y2="8" width="0.127" layer="21"/>
<wire x1="0" y1="8" x2="-0.1" y2="8" width="0.127" layer="21"/>
<wire x1="-0.1" y1="8" x2="-0.2" y2="8" width="0.127" layer="21"/>
<wire x1="-0.2" y1="8" x2="-0.3" y2="8" width="0.127" layer="21"/>
<wire x1="-0.3" y1="8" x2="-0.4" y2="8" width="0.127" layer="21"/>
<wire x1="-0.4" y1="8" x2="-0.5" y2="8" width="0.127" layer="21"/>
<wire x1="-0.5" y1="8" x2="-4.95" y2="8" width="0.127" layer="21"/>
<wire x1="-4.95" y1="8" x2="-4.95" y2="6" width="0.127" layer="21"/>
<wire x1="4.95" y1="8" x2="4.95" y2="6" width="0.127" layer="21"/>
<wire x1="4.45" y1="14" x2="-4.45" y2="14" width="0.127" layer="51"/>
<wire x1="-4.45" y1="14" x2="-4.45" y2="8" width="0.127" layer="51"/>
<wire x1="4.45" y1="14" x2="4.45" y2="8" width="0.127" layer="51"/>
<wire x1="-1.25" y1="2" x2="-1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.1" x2="-1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.2" x2="-1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.3" x2="-1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.4" x2="-1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.5" x2="-1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.6" x2="-1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.7" x2="-1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.8" x2="-1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.9" x2="-1.25" y2="3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3" x2="-1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.1" x2="-1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.2" x2="-1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.3" x2="-1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.4" x2="-1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.5" x2="-1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.6" x2="-1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.7" x2="-1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.8" x2="-1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.9" x2="-1.25" y2="4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="4" x2="-3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.9" x2="-3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.8" x2="-3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.7" x2="-3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.6" x2="-3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.5" x2="-3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.4" x2="-3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.3" x2="-3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.2" x2="-3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.1" x2="-3.75" y2="3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3" x2="-3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.9" x2="-3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.8" x2="-3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.7" x2="-3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.6" x2="-3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.5" x2="-3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.4" x2="-3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.3" x2="-3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.2" x2="-3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.1" x2="-3.75" y2="2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2" x2="-3.5" y2="2" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2" x2="-1.5" y2="2" width="0.127" layer="21"/>
<wire x1="-1.5" y1="2" x2="-1.25" y2="2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.1" x2="-1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.2" x2="-1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.3" x2="-1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.4" x2="-1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.5" x2="-1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.6" x2="-1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.7" x2="-1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.8" x2="-1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.9" x2="-1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3" x2="-1.25" y2="3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.1" x2="-1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.2" x2="-1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.3" x2="-1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.4" x2="-1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.5" x2="-1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.6" x2="-1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.7" x2="-1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.8" x2="-1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.9" x2="-1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="4" x2="1.5" y2="4" width="0.127" layer="21"/>
<wire x1="3.5" y1="4" x2="3.75" y2="4" width="0.127" layer="21"/>
<wire x1="3.75" y1="2" x2="3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.1" x2="3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.2" x2="3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.3" x2="3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.4" x2="3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.5" x2="3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.6" x2="3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.7" x2="3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.8" x2="3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.9" x2="3.75" y2="3" width="0.127" layer="21"/>
<wire x1="3.75" y1="3" x2="3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.1" x2="3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.2" x2="3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.3" x2="3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.4" x2="3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.5" x2="3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.6" x2="3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.7" x2="3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.8" x2="3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.9" x2="3.75" y2="4" width="0.127" layer="21"/>
<wire x1="1.25" y1="4" x2="1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.9" x2="1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.8" x2="1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.7" x2="1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.6" x2="1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.5" x2="1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.4" x2="1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.3" x2="1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.2" x2="1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.1" x2="1.25" y2="3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3" x2="1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.9" x2="1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.8" x2="1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.7" x2="1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.6" x2="1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.5" x2="1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.4" x2="1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.3" x2="1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.2" x2="1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.1" x2="1.25" y2="2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2" x2="3.75" y2="2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.1" x2="3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.2" x2="3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.3" x2="3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.4" x2="3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.5" x2="3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.6" x2="3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.7" x2="3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.8" x2="3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.9" x2="3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="3" x2="3.75" y2="3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.1" x2="3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.2" x2="3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.3" x2="3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.4" x2="3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.5" x2="3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.6" x2="3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.7" x2="3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.8" x2="3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.9" x2="3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2" x2="-3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.9" x2="-3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.8" x2="-3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.7" x2="-3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.6" x2="-3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.5" x2="-1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.5" x2="-1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.6" x2="-1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.7" x2="-1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.8" x2="-1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.9" x2="-1.5" y2="2" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.6" x2="-1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.7" x2="-1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.8" x2="-1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.9" x2="-1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="1.5" y1="2" x2="1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.9" x2="1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.8" x2="1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.7" x2="1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.6" x2="1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.5" x2="3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.5" x2="3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.6" x2="3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.7" x2="3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.8" x2="3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.9" x2="3.5" y2="2" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.6" x2="3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.7" x2="3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.8" x2="3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.9" x2="3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-2.5" y1="0" x2="-2.5" y2="1.5" width="1.778" layer="51"/>
<wire x1="2.5" y1="0" x2="2.5" y2="1.5" width="1.778" layer="51"/>
<wire x1="-3.5" y1="14" x2="-3.5" y2="8" width="0.127" layer="51"/>
<text x="-5.08" y="-3.81" size="1.778" layer="25">&gt;NAME</text>
<text x="-5.08" y="14.605" size="1.778" layer="27">&gt;VALUE</text>
<wire x1="-0.5" y1="8" x2="-0.5" y2="14" width="0.127" layer="51"/>
<wire x1="-0.4" y1="8" x2="-0.4" y2="14" width="0.127" layer="51"/>
<wire x1="-0.3" y1="8" x2="-0.3" y2="14" width="0.127" layer="51"/>
<wire x1="-0.2" y1="8" x2="-0.2" y2="14" width="0.127" layer="51"/>
<wire x1="-0.1" y1="8" x2="-0.1" y2="14" width="0.127" layer="51"/>
<wire x1="0" y1="8" x2="0" y2="14" width="0.127" layer="51"/>
<wire x1="0.1" y1="8" x2="0.1" y2="14" width="0.127" layer="51"/>
<wire x1="0.2" y1="8" x2="0.2" y2="14" width="0.127" layer="51"/>
<wire x1="0.3" y1="8" x2="0.3" y2="14" width="0.127" layer="51"/>
<wire x1="0.4" y1="8" x2="0.4" y2="14" width="0.127" layer="51"/>
<wire x1="0.5" y1="8" x2="0.5" y2="14" width="0.127" layer="51"/>
</package>
<package name="XT30PW-M">
<description>AMASS XT30PW male type connector</description>
<pad name="+" x="-2.5" y="0" drill="1.8"/>
<pad name="-" x="2.5" y="0" drill="1.8"/>
<pad name="P$3" x="-5.5" y="10" drill="1.1"/>
<pad name="P$4" x="5.5" y="10" drill="1.1"/>
<wire x1="-3" y1="5" x2="-2" y2="5" width="0.127" layer="21"/>
<wire x1="-2.5" y1="4.5" x2="-2.5" y2="5.5" width="0.127" layer="21"/>
<wire x1="-6.65" y1="11" x2="-4.95" y2="11" width="0.127" layer="21"/>
<wire x1="-4.95" y1="11" x2="4.95" y2="11" width="0.127" layer="21"/>
<wire x1="4.95" y1="11" x2="6.65" y2="11" width="0.127" layer="21"/>
<wire x1="-6.65" y1="9" x2="-4.95" y2="9" width="0.127" layer="21"/>
<wire x1="-4.95" y1="9" x2="4.95" y2="9" width="0.127" layer="21"/>
<wire x1="4.95" y1="9" x2="6.65" y2="9" width="0.127" layer="21"/>
<wire x1="-6.65" y1="11" x2="-6.65" y2="9" width="0.127" layer="21"/>
<wire x1="6.65" y1="11" x2="6.65" y2="9" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2" x2="-1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.1" x2="-1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.2" x2="-1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.3" x2="-1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.4" x2="-1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.5" x2="-1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.6" x2="-1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.7" x2="-1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.8" x2="-1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="-1.25" y1="2.9" x2="-1.25" y2="3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3" x2="-1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.1" x2="-1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.2" x2="-1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.3" x2="-1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.4" x2="-1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.5" x2="-1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.6" x2="-1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.7" x2="-1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.8" x2="-1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.9" x2="-3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.8" x2="-3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.7" x2="-3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.6" x2="-3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.5" x2="-3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.4" x2="-3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.3" x2="-3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.2" x2="-3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.1" x2="-3.75" y2="3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3" x2="-3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.9" x2="-3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.8" x2="-3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.7" x2="-3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.6" x2="-3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.5" x2="-3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.4" x2="-3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.3" x2="-3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.2" x2="-3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.1" x2="-3.75" y2="2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2" x2="-3.5" y2="2" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2" x2="-1.5" y2="2" width="0.127" layer="21"/>
<wire x1="-1.5" y1="2" x2="-1.25" y2="2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.1" x2="-1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.2" x2="-1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.3" x2="-1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.4" x2="-1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.5" x2="-1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.6" x2="-1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.7" x2="-1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.8" x2="-1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="-3.75" y1="2.9" x2="-1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3" x2="-1.25" y2="3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.1" x2="-1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.2" x2="-1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.3" x2="-1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.4" x2="-1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.5" x2="-1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.6" x2="-1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.7" x2="-1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.8" x2="-1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="9" x2="1.5" y2="9" width="0.127" layer="21"/>
<wire x1="3.5" y1="9" x2="3.75" y2="9" width="0.127" layer="21"/>
<wire x1="3.75" y1="2" x2="3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.1" x2="3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.2" x2="3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.3" x2="3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.4" x2="3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.5" x2="3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.6" x2="3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.7" x2="3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.8" x2="3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="3.75" y1="2.9" x2="3.75" y2="3" width="0.127" layer="21"/>
<wire x1="3.75" y1="3" x2="3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.1" x2="3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.2" x2="3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.3" x2="3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.4" x2="3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.5" x2="3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.6" x2="3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.7" x2="3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.8" x2="3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.9" x2="1.25" y2="3.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.8" x2="1.25" y2="3.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.7" x2="1.25" y2="3.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.6" x2="1.25" y2="3.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.5" x2="1.25" y2="3.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.4" x2="1.25" y2="3.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.3" x2="1.25" y2="3.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.2" x2="1.25" y2="3.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.1" x2="1.25" y2="3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3" x2="1.25" y2="2.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.9" x2="1.25" y2="2.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.8" x2="1.25" y2="2.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.7" x2="1.25" y2="2.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.6" x2="1.25" y2="2.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.5" x2="1.25" y2="2.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.4" x2="1.25" y2="2.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.3" x2="1.25" y2="2.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.2" x2="1.25" y2="2.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.1" x2="1.25" y2="2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2" x2="3.75" y2="2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.1" x2="3.75" y2="2.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.2" x2="3.75" y2="2.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.3" x2="3.75" y2="2.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.4" x2="3.75" y2="2.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.5" x2="3.75" y2="2.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.6" x2="3.75" y2="2.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.7" x2="3.75" y2="2.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.8" x2="3.75" y2="2.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="2.9" x2="3.75" y2="2.9" width="0.127" layer="21"/>
<wire x1="1.25" y1="3" x2="3.75" y2="3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.1" x2="3.75" y2="3.1" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.2" x2="3.75" y2="3.2" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.3" x2="3.75" y2="3.3" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.4" x2="3.75" y2="3.4" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.5" x2="3.75" y2="3.5" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.6" x2="3.75" y2="3.6" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.7" x2="3.75" y2="3.7" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.8" x2="3.75" y2="3.8" width="0.127" layer="21"/>
<wire x1="1.25" y1="3.9" x2="3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2" x2="-3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.9" x2="-3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.8" x2="-3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.7" x2="-3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.6" x2="-3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.5" x2="-1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.5" x2="-1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.6" x2="-1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.7" x2="-1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.8" x2="-1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.9" x2="-1.5" y2="2" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.6" x2="-1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.7" x2="-1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.8" x2="-1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.9" x2="-1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="1.5" y1="2" x2="1.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.9" x2="1.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.8" x2="1.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.7" x2="1.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.6" x2="1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.5" x2="3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.5" x2="3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.6" x2="3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.7" x2="3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.8" x2="3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.9" x2="3.5" y2="2" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.6" x2="3.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.7" x2="3.5" y2="1.7" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.8" x2="3.5" y2="1.8" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.9" x2="3.5" y2="1.9" width="0.127" layer="21"/>
<wire x1="-2.5" y1="0" x2="-2.5" y2="1.5" width="1.778" layer="51"/>
<wire x1="2.5" y1="0" x2="2.5" y2="1.5" width="1.778" layer="51"/>
<text x="-5.08" y="-3.81" size="1.778" layer="25">&gt;NAME</text>
<text x="-5.3" y="13.5" size="1.778" layer="27">&gt;VALUE</text>
<wire x1="-4.95" y1="13" x2="4.95" y2="13" width="0.127" layer="21"/>
<wire x1="-4.95" y1="13" x2="-4.95" y2="11" width="0.127" layer="21"/>
<wire x1="4.95" y1="13" x2="4.95" y2="11" width="0.127" layer="21"/>
<wire x1="-4.95" y1="4" x2="-3.75" y2="4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="4" x2="-1.25" y2="4" width="0.127" layer="21"/>
<wire x1="-1.25" y1="4" x2="1.25" y2="4" width="0.127" layer="21"/>
<wire x1="1.25" y1="4" x2="3.75" y2="4" width="0.127" layer="21"/>
<wire x1="3.75" y1="4" x2="4.95" y2="4" width="0.127" layer="21"/>
<wire x1="-3.75" y1="3.9" x2="-1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="-3.75" y1="4" x2="-3.75" y2="3.9" width="0.127" layer="21"/>
<wire x1="-1.25" y1="3.9" x2="-1.25" y2="4" width="0.127" layer="21"/>
<wire x1="1.25" y1="4" x2="1.25" y2="3.9" width="0.127" layer="21"/>
<wire x1="3.75" y1="3.9" x2="3.75" y2="4" width="0.127" layer="21"/>
<wire x1="-4.95" y1="9" x2="-4.95" y2="4" width="0.127" layer="21"/>
<wire x1="4.95" y1="9" x2="4.95" y2="4" width="0.127" layer="21"/>
<wire x1="-4.95" y1="11" x2="-4.95" y2="9" width="0.127" layer="51"/>
<wire x1="4.95" y1="11" x2="4.95" y2="9" width="0.127" layer="51"/>
</package>
<package name="XT30UPB-F">
<description>AMASS XT30UPB female type connector</description>
<text x="-3.5" y="-5" size="1.778" layer="25">&gt;NAME</text>
<text x="-4.5" y="3" size="1.778" layer="27">&gt;VALUE</text>
<pad name="-" x="-2.5" y="0" drill="1.8"/>
<pad name="+" x="2.5" y="0" drill="1.8"/>
<wire x1="-5.1" y1="0.6" x2="-5.1" y2="-0.6" width="0.127" layer="21"/>
<wire x1="-5.1" y1="-0.6" x2="-3.1" y2="-2.6" width="0.127" layer="21" curve="90"/>
<wire x1="-3.1" y1="-2.6" x2="5.1" y2="-2.6" width="0.127" layer="21"/>
<wire x1="-5.1" y1="0.6" x2="-3.1" y2="2.6" width="0.127" layer="21" curve="-90"/>
<wire x1="-3.1" y1="2.6" x2="5.1" y2="2.6" width="0.127" layer="21"/>
<wire x1="5.1" y1="2.6" x2="5.1" y2="-2.6" width="0.127" layer="21"/>
<wire x1="-2.5" y1="2" x2="-3.4" y2="2" width="0.127" layer="21"/>
<wire x1="-3.4" y1="2" x2="-4.4" y2="1" width="0.127" layer="21"/>
<wire x1="-4.4" y1="1" x2="-4.4" y2="-1" width="0.127" layer="21"/>
<wire x1="-4.4" y1="-1" x2="-3.4" y2="-2" width="0.127" layer="21"/>
<wire x1="-3.4" y1="-2" x2="-2.5" y2="-2" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2" x2="-0.5" y2="0" width="0.127" layer="21" curve="90"/>
<wire x1="0.5" y1="0" x2="2.5" y2="-2" width="0.127" layer="21" curve="90"/>
<wire x1="2.5" y1="-2" x2="4.4" y2="-2" width="0.127" layer="21"/>
<wire x1="4.4" y1="-2" x2="4.4" y2="2" width="0.127" layer="21"/>
<wire x1="4.4" y1="2" x2="2.5" y2="2" width="0.127" layer="21"/>
<wire x1="2.5" y1="2" x2="0.5" y2="0" width="0.127" layer="21" curve="90"/>
<wire x1="-0.5" y1="0" x2="-2.5" y2="2" width="0.127" layer="21" curve="90"/>
<wire x1="-0.5" y1="0" x2="0.5" y2="0" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2" x2="2.5" y2="-2" width="0.127" layer="21"/>
<wire x1="-2.5" y1="2" x2="2.5" y2="2" width="0.127" layer="21"/>
<circle x="-2.5" y="0" radius="1.6" width="0.127" layer="51"/>
<circle x="2.5" y="0" radius="1.6" width="0.127" layer="51"/>
<wire x1="5.5" y1="0" x2="6.5" y2="0" width="0.127" layer="21"/>
<wire x1="6" y1="0.5" x2="6" y2="-0.5" width="0.127" layer="21"/>
</package>
<package name="XT30UPB-M">
<description>AMASS XT30UPB male type connector</description>
<text x="-3.5" y="-5" size="1.778" layer="25">&gt;NAME</text>
<text x="-4.5" y="3" size="1.778" layer="27">&gt;VALUE</text>
<pad name="-" x="-2.5" y="0" drill="1.8"/>
<pad name="+" x="2.5" y="0" drill="1.8"/>
<wire x1="-5.1" y1="0.6" x2="-5.1" y2="-0.6" width="0.127" layer="21"/>
<wire x1="-5.1" y1="-0.6" x2="-3.1" y2="-2.6" width="0.127" layer="21" curve="90"/>
<wire x1="-3.1" y1="-2.6" x2="5.1" y2="-2.6" width="0.127" layer="21"/>
<wire x1="-5.1" y1="0.6" x2="-3.1" y2="2.6" width="0.127" layer="21" curve="-90"/>
<wire x1="-3.1" y1="2.6" x2="5.1" y2="2.6" width="0.127" layer="21"/>
<wire x1="5.1" y1="2.6" x2="5.1" y2="-2.6" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2.25" x2="-4.75" y2="1" width="0.127" layer="21"/>
<wire x1="-4.75" y1="1" x2="-4.75" y2="-1" width="0.127" layer="21"/>
<wire x1="-4.75" y1="-1" x2="-3.5" y2="-2.25" width="0.127" layer="21"/>
<wire x1="4.75" y1="-2.25" x2="4.75" y2="2.25" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-2.25" x2="4.75" y2="-2.25" width="0.127" layer="21"/>
<wire x1="-3.5" y1="2.25" x2="4.75" y2="2.25" width="0.127" layer="21"/>
<wire x1="5.5" y1="0" x2="6.5" y2="0" width="0.127" layer="21"/>
<wire x1="6" y1="0.5" x2="6" y2="-0.5" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="CON-2">
<wire x1="-5.08" y1="5.715" x2="-5.08" y2="-4.318" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-4.318" x2="-3.048" y2="-6.35" width="0.4064" layer="94"/>
<wire x1="-3.048" y1="-6.35" x2="-0.762" y2="-6.35" width="0.4064" layer="94"/>
<wire x1="-0.762" y1="-6.35" x2="1.27" y2="-4.318" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-4.318" x2="1.27" y2="5.715" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="5.715" x2="1.27" y2="5.715" width="0.4064" layer="94"/>
<text x="-3.81" y="-8.89" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="7.112" size="1.778" layer="95">&gt;NAME</text>
<pin name="+" x="5.08" y="2.54" visible="pad" length="middle" direction="pwr" rot="R180"/>
<pin name="-" x="5.08" y="-2.54" visible="pad" length="middle" direction="pwr" rot="R180"/>
<wire x1="0" y1="2.54" x2="-1.778" y2="2.54" width="1.27" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.778" y2="-2.54" width="1.27" layer="94"/>
<wire x1="-4.445" y1="2.54" x2="-2.921" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-3.683" y1="3.302" x2="-3.683" y2="1.778" width="0.4064" layer="94"/>
<wire x1="-4.445" y1="-2.54" x2="-2.921" y2="-2.54" width="0.4064" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="XT30" prefix="CON">
<description>&lt;b&gt;AMASS XT30 connector&lt;/b&gt;

&lt;p&gt;Store in Japan&lt;/p&gt;
&lt;ul&gt;
&lt;li&gt;&lt;a href="https://szc.jp/ams-xt30"&gt;AMASS XT30 connector&lt;/a&gt;&lt;/li&gt;
&lt;/ul&gt;</description>
<gates>
<gate name="G$1" symbol="CON-2" x="0" y="0"/>
</gates>
<devices>
<device name="PW-F" package="XT30PW-F">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PW-M" package="XT30PW-M">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="UPB-F" package="XT30UPB-F">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="UPB-M" package="XT30UPB-M">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-garry" urn="urn:adsk.eagle:library:147">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;a href="www.mpe-connector.de"&gt;Menufacturer&lt;/a&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="332-02" urn="urn:adsk.eagle:footprint:6784/1" library_version="2">
<description>&lt;b&gt;2 Pin - 2mm Dual Row&lt;/b&gt;&lt;p&gt;
Source: www.mpe-connector.de / garry_shortform_2012.pdf</description>
<wire x1="-0.85" y1="-1.9" x2="0.85" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="0.85" y1="-1.9" x2="0.85" y2="-0.4" width="0.2032" layer="21"/>
<wire x1="0.85" y1="0.4" x2="0.85" y2="1.9" width="0.2032" layer="21"/>
<wire x1="0.85" y1="1.9" x2="-0.85" y2="1.9" width="0.2032" layer="21"/>
<wire x1="-0.85" y1="1.9" x2="-0.85" y2="0.4" width="0.2032" layer="21"/>
<wire x1="-0.85" y1="-0.4" x2="-0.85" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="-0.85" y1="0.4" x2="-0.85" y2="-0.4" width="0.2032" layer="21" curve="-129.185"/>
<wire x1="0.85" y1="-0.4" x2="0.85" y2="0.4" width="0.2032" layer="21" curve="-129.185"/>
<pad name="1" x="0" y="-1" drill="0.9" diameter="1.27"/>
<pad name="2" x="0" y="1" drill="0.9" diameter="1.27"/>
<text x="-0.65" y="-1.75" size="0.3048" layer="21" font="vector">1</text>
<text x="-0.62" y="-3.81" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.62" y="2.54" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.25" y1="-1.25" x2="0.25" y2="-0.75" layer="51"/>
<rectangle x1="-0.25" y1="0.75" x2="0.25" y2="1.25" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="332-02" urn="urn:adsk.eagle:package:6810/1" type="box" library_version="2">
<description>2 Pin - 2mm Dual Row
Source: www.mpe-connector.de / garry_shortform_2012.pdf</description>
<packageinstances>
<packageinstance name="332-02"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MV" urn="urn:adsk.eagle:symbol:6783/1" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="332-02" urn="urn:adsk.eagle:component:6832/2" prefix="X" library_version="2">
<description>&lt;b&gt;2 Pin - 2mm Dual Row&lt;/b&gt;&lt;p&gt;
Source: www.mpe-connector.de / garry_shortform_2012.pdf</description>
<gates>
<gate name="-1" symbol="MV" x="-10.16" y="0" addlevel="always"/>
<gate name="-2" symbol="MV" x="10.16" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="332-02">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:6810/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="7" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X03" urn="urn:adsk.eagle:footprint:22340/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-3.8862" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.81" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
</package>
<package name="1X03/90" urn="urn:adsk.eagle:footprint:22341/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="0" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-4.445" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="5.715" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="1X03" urn="urn:adsk.eagle:package:22458/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X03"/>
</packageinstances>
</package3d>
<package3d name="1X03/90" urn="urn:adsk.eagle:package:22459/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X03/90"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD3" urn="urn:adsk.eagle:symbol:22339/1" library_version="4">
<wire x1="-6.35" y1="-5.08" x2="1.27" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-5.08" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X3" urn="urn:adsk.eagle:component:22524/4" prefix="JP" uservalue="yes" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD3" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X03">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22458/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="92" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X03/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22459/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="17" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0.508" drill="0">
<clearance class="0" value="0.254"/>
</class>
</classes>
<parts>
<part name="ARDUINO_NANO1" library="ArduinoNanoV30" deviceset="ARDUINO_NANO" device=""/>
<part name="IC1" library="st-microelectronics" library_urn="urn:adsk.eagle:library:368" deviceset="L293D" device="" package3d_urn="urn:adsk.eagle:package:26820/1"/>
<part name="IC2" library="st-microelectronics" library_urn="urn:adsk.eagle:library:368" deviceset="L293D" device="" package3d_urn="urn:adsk.eagle:package:26820/1"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="CON1" library="amass" deviceset="XT30" device="UPB-M"/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="MOTOR3" library="con-garry" library_urn="urn:adsk.eagle:library:147" deviceset="332-02" device="" package3d_urn="urn:adsk.eagle:package:6810/1"/>
<part name="MOTOR4" library="con-garry" library_urn="urn:adsk.eagle:library:147" deviceset="332-02" device="" package3d_urn="urn:adsk.eagle:package:6810/1"/>
<part name="MOTOR1" library="con-garry" library_urn="urn:adsk.eagle:library:147" deviceset="332-02" device="" package3d_urn="urn:adsk.eagle:package:6810/1"/>
<part name="MOTOR2" library="con-garry" library_urn="urn:adsk.eagle:library:147" deviceset="332-02" device="" package3d_urn="urn:adsk.eagle:package:6810/1"/>
<part name="JP1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="JP2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="JP3" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="JP4" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="GND12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND15" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="ARDUINO_NANO1" gate="G$1" x="30.48" y="48.26" smashed="yes" rot="R180">
<attribute name="NAME" x="45.72" y="78.74" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="45.72" y="81.28" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="IC1" gate="G$1" x="114.3" y="30.48" smashed="yes" rot="R180">
<attribute name="NAME" x="124.46" y="9.144" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="124.46" y="53.34" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="IC2" gate="G$1" x="114.3" y="81.28" smashed="yes" rot="R180">
<attribute name="NAME" x="124.46" y="59.944" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="124.46" y="104.14" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND1" gate="1" x="96.52" y="27.94" smashed="yes" rot="R270">
<attribute name="VALUE" x="93.98" y="30.48" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND2" gate="1" x="96.52" y="33.02" smashed="yes" rot="R270">
<attribute name="VALUE" x="93.98" y="35.56" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND3" gate="1" x="132.08" y="27.94" smashed="yes" rot="R90">
<attribute name="VALUE" x="134.62" y="25.4" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND4" gate="1" x="132.08" y="33.02" smashed="yes" rot="R90">
<attribute name="VALUE" x="134.62" y="30.48" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND5" gate="1" x="132.08" y="78.74" smashed="yes" rot="R90">
<attribute name="VALUE" x="134.62" y="76.2" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND6" gate="1" x="132.08" y="83.82" smashed="yes" rot="R90">
<attribute name="VALUE" x="134.62" y="81.28" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND7" gate="1" x="96.52" y="78.74" smashed="yes" rot="R270">
<attribute name="VALUE" x="93.98" y="81.28" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND8" gate="1" x="96.52" y="83.82" smashed="yes" rot="R270">
<attribute name="VALUE" x="93.98" y="86.36" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND9" gate="1" x="53.34" y="43.18" smashed="yes" rot="R90">
<attribute name="VALUE" x="55.88" y="40.64" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND10" gate="1" x="7.62" y="38.1" smashed="yes" rot="R270">
<attribute name="VALUE" x="5.08" y="40.64" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="CON1" gate="G$1" x="187.96" y="38.1" smashed="yes">
<attribute name="VALUE" x="184.15" y="29.21" size="1.778" layer="96"/>
<attribute name="NAME" x="184.15" y="45.212" size="1.778" layer="95"/>
</instance>
<instance part="GND11" gate="1" x="195.58" y="35.56" smashed="yes" rot="R90">
<attribute name="VALUE" x="198.12" y="33.02" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR3" gate="-1" x="147.32" y="71.12" smashed="yes" rot="R90">
<attribute name="NAME" x="148.082" y="73.66" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="145.923" y="70.358" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR3" gate="-2" x="147.32" y="91.44" smashed="yes" rot="R90">
<attribute name="NAME" x="148.082" y="93.98" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="145.923" y="90.678" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR4" gate="-1" x="83.82" y="78.74" smashed="yes" rot="R90">
<attribute name="NAME" x="84.582" y="81.28" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="82.423" y="77.978" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR4" gate="-2" x="83.82" y="99.06" smashed="yes" rot="R90">
<attribute name="NAME" x="84.582" y="101.6" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="82.423" y="98.298" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR1" gate="-1" x="157.48" y="20.32" smashed="yes" rot="R90">
<attribute name="NAME" x="158.242" y="22.86" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="156.083" y="19.558" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR1" gate="-2" x="157.48" y="40.64" smashed="yes" rot="R90">
<attribute name="NAME" x="158.242" y="43.18" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="156.083" y="39.878" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR2" gate="-1" x="93.98" y="22.86" smashed="yes" rot="R90">
<attribute name="NAME" x="94.742" y="25.4" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="92.583" y="22.098" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="MOTOR2" gate="-2" x="93.98" y="43.18" smashed="yes" rot="R90">
<attribute name="NAME" x="94.742" y="45.72" size="1.524" layer="95" rot="R90"/>
<attribute name="VALUE" x="92.583" y="42.418" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="JP1" gate="A" x="-20.32" y="30.48" smashed="yes" rot="R180">
<attribute name="NAME" x="-13.97" y="24.765" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-13.97" y="38.1" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP2" gate="A" x="-20.32" y="48.26" smashed="yes" rot="R180">
<attribute name="NAME" x="-13.97" y="42.545" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-13.97" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP3" gate="A" x="-20.32" y="60.96" smashed="yes" rot="R180">
<attribute name="NAME" x="-13.97" y="55.245" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-13.97" y="68.58" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP4" gate="A" x="-20.32" y="76.2" smashed="yes" rot="R180">
<attribute name="NAME" x="-13.97" y="70.485" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-13.97" y="83.82" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND12" gate="1" x="-15.24" y="78.74" smashed="yes" rot="R90">
<attribute name="VALUE" x="-12.7" y="76.2" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND13" gate="1" x="-15.24" y="63.5" smashed="yes" rot="R90">
<attribute name="VALUE" x="-12.7" y="60.96" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND14" gate="1" x="-15.24" y="50.8" smashed="yes" rot="R90">
<attribute name="VALUE" x="-12.7" y="48.26" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND15" gate="1" x="-15.24" y="33.02" smashed="yes" rot="R90">
<attribute name="VALUE" x="-12.7" y="30.48" size="1.778" layer="96" rot="R90"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="GND3"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND4"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND1"/>
<pinref part="GND3" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND2"/>
<pinref part="GND4" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND1"/>
<pinref part="GND5" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND2"/>
<pinref part="GND6" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND3"/>
<pinref part="GND7" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND4"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="GND@1"/>
<pinref part="GND9" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="GND@2"/>
<pinref part="GND10" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="CON1" gate="G$1" pin="-"/>
<pinref part="GND11" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="3"/>
<pinref part="GND12" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="3"/>
<pinref part="GND13" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="3"/>
<pinref part="GND14" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="3"/>
<pinref part="GND15" gate="1" pin="GND"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D2"/>
<wire x1="50.8" y1="45.72" x2="137.16" y2="45.72" width="0.1524" layer="91"/>
<wire x1="137.16" y1="45.72" x2="137.16" y2="17.78" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="1A"/>
<wire x1="129.54" y1="17.78" x2="137.16" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D3"/>
<wire x1="50.8" y1="48.26" x2="63.5" y2="48.26" width="0.1524" layer="91"/>
<wire x1="63.5" y1="48.26" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
<wire x1="63.5" y1="53.34" x2="142.24" y2="53.34" width="0.1524" layer="91"/>
<wire x1="142.24" y1="53.34" x2="142.24" y2="43.18" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="2A"/>
<wire x1="142.24" y1="43.18" x2="129.54" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D4"/>
<wire x1="50.8" y1="50.8" x2="66.04" y2="50.8" width="0.1524" layer="91"/>
<wire x1="66.04" y1="50.8" x2="66.04" y2="43.18" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="3A"/>
<wire x1="66.04" y1="43.18" x2="99.06" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D5"/>
<wire x1="50.8" y1="53.34" x2="147.32" y2="53.34" width="0.1524" layer="91"/>
<wire x1="147.32" y1="53.34" x2="147.32" y2="12.7" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="1-2EN"/>
<wire x1="147.32" y1="12.7" x2="129.54" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D6"/>
<wire x1="50.8" y1="55.88" x2="96.52" y2="55.88" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="3-4EN"/>
<wire x1="99.06" y1="48.26" x2="96.52" y2="48.26" width="0.1524" layer="91"/>
<wire x1="96.52" y1="48.26" x2="96.52" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D7"/>
<wire x1="50.8" y1="58.42" x2="60.96" y2="58.42" width="0.1524" layer="91"/>
<wire x1="60.96" y1="58.42" x2="60.96" y2="17.78" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="4A"/>
<wire x1="60.96" y1="17.78" x2="99.06" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D9"/>
<wire x1="50.8" y1="63.5" x2="68.58" y2="63.5" width="0.1524" layer="91"/>
<wire x1="68.58" y1="63.5" x2="68.58" y2="58.42" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="1-2EN"/>
<wire x1="68.58" y1="58.42" x2="129.54" y2="58.42" width="0.1524" layer="91"/>
<wire x1="129.54" y1="58.42" x2="129.54" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D10"/>
<wire x1="50.8" y1="66.04" x2="66.04" y2="66.04" width="0.1524" layer="91"/>
<wire x1="66.04" y1="66.04" x2="66.04" y2="99.06" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="3-4EN"/>
<wire x1="66.04" y1="99.06" x2="99.06" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D8"/>
<wire x1="50.8" y1="60.96" x2="132.08" y2="60.96" width="0.1524" layer="91"/>
<wire x1="132.08" y1="60.96" x2="132.08" y2="68.58" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="1A"/>
<wire x1="132.08" y1="68.58" x2="129.54" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D11"/>
<wire x1="50.8" y1="68.58" x2="66.04" y2="68.58" width="0.1524" layer="91"/>
<wire x1="66.04" y1="68.58" x2="66.04" y2="58.42" width="0.1524" layer="91"/>
<wire x1="66.04" y1="58.42" x2="137.16" y2="58.42" width="0.1524" layer="91"/>
<wire x1="137.16" y1="58.42" x2="137.16" y2="93.98" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="2A"/>
<wire x1="137.16" y1="93.98" x2="129.54" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D12"/>
<pinref part="IC2" gate="G$1" pin="4A"/>
<wire x1="50.8" y1="71.12" x2="99.06" y2="71.12" width="0.1524" layer="91"/>
<wire x1="99.06" y1="71.12" x2="99.06" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="D13"/>
<wire x1="10.16" y1="71.12" x2="10.16" y2="93.98" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="3A"/>
<wire x1="10.16" y1="93.98" x2="99.06" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="5V"/>
<wire x1="10.16" y1="43.18" x2="-5.08" y2="43.18" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="43.18" x2="-5.08" y2="27.94" width="0.1524" layer="91"/>
<junction x="-5.08" y="43.18"/>
<wire x1="-5.08" y1="73.66" x2="-5.08" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="58.42" x2="-5.08" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="45.72" x2="-5.08" y2="43.18" width="0.1524" layer="91"/>
<wire x1="10.16" y1="43.18" x2="38.1" y2="43.18" width="0.1524" layer="91"/>
<wire x1="38.1" y1="43.18" x2="38.1" y2="30.48" width="0.1524" layer="91"/>
<junction x="10.16" y="43.18"/>
<wire x1="88.9" y1="35.56" x2="91.44" y2="35.56" width="0.1524" layer="91"/>
<wire x1="91.44" y1="35.56" x2="91.44" y2="30.48" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="VCC1"/>
<wire x1="91.44" y1="30.48" x2="91.44" y2="12.7" width="0.1524" layer="91"/>
<wire x1="91.44" y1="12.7" x2="99.06" y2="12.7" width="0.1524" layer="91"/>
<pinref part="IC2" gate="G$1" pin="VCC1"/>
<wire x1="99.06" y1="63.5" x2="88.9" y2="63.5" width="0.1524" layer="91"/>
<wire x1="88.9" y1="63.5" x2="88.9" y2="35.56" width="0.1524" layer="91"/>
<wire x1="38.1" y1="30.48" x2="91.44" y2="30.48" width="0.1524" layer="91"/>
<junction x="91.44" y="30.48"/>
<pinref part="JP4" gate="A" pin="1"/>
<wire x1="-17.78" y1="73.66" x2="-5.08" y2="73.66" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="1"/>
<wire x1="-17.78" y1="58.42" x2="-5.08" y2="58.42" width="0.1524" layer="91"/>
<junction x="-5.08" y="58.42"/>
<pinref part="JP2" gate="A" pin="1"/>
<wire x1="-17.78" y1="45.72" x2="-5.08" y2="45.72" width="0.1524" layer="91"/>
<junction x="-5.08" y="45.72"/>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="-17.78" y1="27.94" x2="-5.08" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="MOTOR1" gate="-1" pin="S"/>
<wire x1="157.48" y1="17.78" x2="149.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="149.86" y1="17.78" x2="149.86" y2="22.86" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="1Y"/>
<wire x1="149.86" y1="22.86" x2="129.54" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="2Y"/>
<pinref part="MOTOR1" gate="-2" pin="S"/>
<wire x1="129.54" y1="38.1" x2="157.48" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="1Y"/>
<wire x1="129.54" y1="73.66" x2="142.24" y2="73.66" width="0.1524" layer="91"/>
<wire x1="142.24" y1="73.66" x2="142.24" y2="68.58" width="0.1524" layer="91"/>
<pinref part="MOTOR3" gate="-1" pin="S"/>
<wire x1="142.24" y1="68.58" x2="147.32" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="MOTOR3" gate="-2" pin="S"/>
<pinref part="IC2" gate="G$1" pin="2Y"/>
<wire x1="147.32" y1="88.9" x2="129.54" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="3Y"/>
<pinref part="MOTOR4" gate="-2" pin="S"/>
<wire x1="99.06" y1="88.9" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
<wire x1="83.82" y1="88.9" x2="83.82" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="4Y"/>
<pinref part="MOTOR4" gate="-1" pin="S"/>
<wire x1="99.06" y1="73.66" x2="83.82" y2="73.66" width="0.1524" layer="91"/>
<wire x1="83.82" y1="73.66" x2="83.82" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="3Y"/>
<pinref part="MOTOR2" gate="-2" pin="S"/>
<wire x1="99.06" y1="38.1" x2="93.98" y2="38.1" width="0.1524" layer="91"/>
<wire x1="93.98" y1="38.1" x2="93.98" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="4Y"/>
<pinref part="MOTOR2" gate="-1" pin="S"/>
<wire x1="99.06" y1="22.86" x2="93.98" y2="22.86" width="0.1524" layer="91"/>
<wire x1="93.98" y1="22.86" x2="93.98" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="A0"/>
<wire x1="2.54" y1="76.2" x2="2.54" y2="63.5" width="0.1524" layer="91"/>
<wire x1="2.54" y1="63.5" x2="10.16" y2="63.5" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="2"/>
<wire x1="-17.78" y1="76.2" x2="2.54" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="A2"/>
<wire x1="2.54" y1="48.26" x2="2.54" y2="58.42" width="0.1524" layer="91"/>
<wire x1="2.54" y1="58.42" x2="10.16" y2="58.42" width="0.1524" layer="91"/>
<pinref part="JP2" gate="A" pin="2"/>
<wire x1="-17.78" y1="48.26" x2="2.54" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="A3"/>
<wire x1="5.08" y1="30.48" x2="5.08" y2="55.88" width="0.1524" layer="91"/>
<wire x1="5.08" y1="55.88" x2="10.16" y2="55.88" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="-17.78" y1="30.48" x2="5.08" y2="30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="ARDUINO_NANO1" gate="G$1" pin="A1"/>
<pinref part="JP3" gate="A" pin="2"/>
<wire x1="-17.78" y1="60.96" x2="10.16" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="VCC2"/>
<pinref part="CON1" gate="G$1" pin="+"/>
<wire x1="129.54" y1="99.06" x2="193.04" y2="99.06" width="0.1524" layer="91"/>
<wire x1="193.04" y1="99.06" x2="193.04" y2="48.26" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="VCC2"/>
<wire x1="193.04" y1="48.26" x2="193.04" y2="40.64" width="0.1524" layer="91"/>
<wire x1="129.54" y1="48.26" x2="193.04" y2="48.26" width="0.1524" layer="91"/>
<junction x="193.04" y="48.26"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
