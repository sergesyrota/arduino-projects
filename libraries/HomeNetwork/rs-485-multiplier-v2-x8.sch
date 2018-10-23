<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.7.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting keepoldvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="6" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
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
<library name="con-tycoelectronics">
<description>&lt;b&gt;Tyco Electronics Connector&lt;/b&gt;&lt;p&gt;
http://catalog.tycoelectronics.com&lt;br&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="RJ45-SHIELD2">
<description>&lt;b&gt;RJ45 Low Profile&lt;/b&gt; Shield Type 2&lt;p&gt;
For all RJ45 L, LC, LCT and X Series Models&lt;br&gt;
Source: www.tycoelectronics.com .. ENG_DS_1654001_1099_RJ_L_0507.pdf</description>
<wire x1="8.777" y1="-3.151" x2="8.777" y2="-7.147" width="0.2032" layer="51"/>
<wire x1="-8.777" y1="-7.147" x2="-8.777" y2="-3.151" width="0.2032" layer="51"/>
<wire x1="-8.777" y1="10.819" x2="8.777" y2="10.819" width="0.2032" layer="21"/>
<wire x1="9.7155" y1="-8.18" x2="-9.7155" y2="-8.18" width="0.01" layer="20"/>
<wire x1="8.777" y1="-10.322" x2="-8.777" y2="-10.322" width="0.2032" layer="21"/>
<wire x1="-8.777" y1="-10.322" x2="-8.777" y2="-6.961" width="0.2032" layer="21"/>
<wire x1="8.777" y1="-6.961" x2="8.777" y2="-10.322" width="0.2032" layer="21"/>
<wire x1="-8.777" y1="6.823" x2="-8.777" y2="10.819" width="0.2032" layer="51"/>
<wire x1="8.777" y1="10.819" x2="8.777" y2="6.823" width="0.2032" layer="51"/>
<wire x1="-8.777" y1="-3.337" x2="-8.777" y2="7.009" width="0.2032" layer="21"/>
<wire x1="8.777" y1="7.009" x2="8.777" y2="-3.337" width="0.2032" layer="21"/>
<pad name="4" x="-0.635" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="3" x="-1.905" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="2" x="-3.175" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="5" x="0.635" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="1" x="-4.445" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="6" x="1.905" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="S1" x="-8.128" y="-5.33" drill="1.9" diameter="2.5"/>
<pad name="S2" x="8.128" y="-5.33" drill="1.9" diameter="2.5"/>
<pad name="7" x="3.175" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="8" x="4.445" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="S3" x="-8.128" y="8.76" drill="1.9" diameter="2.5"/>
<pad name="S4" x="8.128" y="8.76" drill="1.9" diameter="2.5"/>
<text x="-9.525" y="-0.635" size="1.778" layer="25" rot="R90">&gt;NAME</text>
<text x="-5.715" y="2.54" size="1.778" layer="27">&gt;VALUE</text>
<rectangle x1="8.85" y1="-8.175" x2="9.775" y2="-7.032" layer="21"/>
<rectangle x1="-9.775" y1="-8.175" x2="-8.85" y2="-7.032" layer="21"/>
<hole x="-5.715" y="0" drill="3.2512"/>
<hole x="5.715" y="0" drill="3.2512"/>
</package>
<package name="RJ45-SHIELD1">
<description>&lt;b&gt;RJ45 Low Profile&lt;/b&gt; Shield Type 1&lt;p&gt;
For all RJ45 N and Z Series Models&lt;br&gt;
Source: www.tycoelectronics.com .. ENG_DS_1654001_1099_RJ_L_0507.pdf</description>
<wire x1="7.777" y1="-0.611" x2="7.777" y2="-5.242" width="0.2032" layer="51"/>
<wire x1="-7.777" y1="-5.242" x2="-7.777" y2="-0.611" width="0.2032" layer="51"/>
<wire x1="-7.777" y1="10.819" x2="7.777" y2="10.819" width="0.2032" layer="21"/>
<wire x1="8.4455" y1="-5.5118" x2="-8.4455" y2="-5.5118" width="0.01" layer="20"/>
<wire x1="7.777" y1="-7.782" x2="-7.777" y2="-7.782" width="0.2032" layer="21"/>
<wire x1="-7.777" y1="-7.782" x2="-7.777" y2="-5.056" width="0.2032" layer="21"/>
<wire x1="7.777" y1="-5.056" x2="7.777" y2="-7.782" width="0.2032" layer="21"/>
<wire x1="-7.777" y1="6.823" x2="-7.777" y2="10.819" width="0.2032" layer="51"/>
<wire x1="7.777" y1="10.819" x2="7.777" y2="6.823" width="0.2032" layer="51"/>
<wire x1="-7.777" y1="-0.797" x2="-7.777" y2="7.009" width="0.2032" layer="21"/>
<wire x1="7.777" y1="7.009" x2="7.777" y2="-0.797" width="0.2032" layer="21"/>
<pad name="4" x="-0.635" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="3" x="-1.905" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="2" x="-3.175" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="5" x="0.635" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="1" x="-4.445" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="6" x="1.905" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="S1" x="-8.128" y="-3.048" drill="1.9" diameter="2.5"/>
<pad name="S2" x="8.128" y="-3.048" drill="1.9" diameter="2.5"/>
<pad name="7" x="3.175" y="6.35" drill="0.9" diameter="1.4"/>
<pad name="8" x="4.445" y="8.89" drill="0.9" diameter="1.4"/>
<pad name="S3" x="-8.128" y="8.76" drill="1.9" diameter="2.5"/>
<pad name="S4" x="8.128" y="8.76" drill="1.9" diameter="2.5"/>
<text x="-9.525" y="-0.635" size="1.778" layer="25" rot="R90">&gt;NAME</text>
<text x="-5.715" y="2.54" size="1.778" layer="27">&gt;VALUE</text>
<rectangle x1="7.85" y1="-5.485" x2="8.775" y2="-4.342" layer="51"/>
<rectangle x1="-8.775" y1="-5.485" x2="-7.85" y2="-4.342" layer="51"/>
<hole x="-5.715" y="0" drill="3.2512"/>
<hole x="5.715" y="0" drill="3.2512"/>
</package>
</packages>
<symbols>
<symbol name="JACK8SHILED4">
<wire x1="-5.461" y1="-10.16" x2="-4.826" y2="-10.16" width="0.127" layer="94"/>
<wire x1="-4.064" y1="-10.16" x2="-3.556" y2="-10.16" width="0.127" layer="94"/>
<wire x1="-2.794" y1="-10.16" x2="-2.286" y2="-10.16" width="0.127" layer="94"/>
<wire x1="4.318" y1="-10.16" x2="4.572" y2="-10.16" width="0.127" layer="94"/>
<wire x1="4.572" y1="-10.16" x2="4.572" y2="-9.652" width="0.127" layer="94"/>
<wire x1="4.572" y1="9.906" x2="4.572" y2="10.414" width="0.127" layer="94"/>
<wire x1="4.572" y1="10.922" x2="4.572" y2="11.43" width="0.127" layer="94"/>
<wire x1="-4.826" y1="11.43" x2="-5.461" y2="11.43" width="0.127" layer="94"/>
<wire x1="-5.461" y1="11.43" x2="-5.461" y2="10.668" width="0.127" layer="94"/>
<wire x1="-5.461" y1="9.652" x2="-5.461" y2="8.128" width="0.127" layer="94"/>
<wire x1="-5.461" y1="7.112" x2="-5.461" y2="5.588" width="0.127" layer="94"/>
<wire x1="-5.461" y1="4.572" x2="-5.461" y2="3.048" width="0.127" layer="94"/>
<wire x1="-5.461" y1="2.032" x2="-5.461" y2="0.508" width="0.127" layer="94"/>
<wire x1="-5.461" y1="-0.508" x2="-5.461" y2="-2.032" width="0.127" layer="94"/>
<wire x1="-5.461" y1="-8.128" x2="-5.461" y2="-10.16" width="0.127" layer="94"/>
<wire x1="4.572" y1="8.636" x2="4.572" y2="9.144" width="0.127" layer="94"/>
<wire x1="4.572" y1="7.366" x2="4.572" y2="7.874" width="0.127" layer="94"/>
<wire x1="4.572" y1="6.096" x2="4.572" y2="6.604" width="0.127" layer="94"/>
<wire x1="4.572" y1="4.826" x2="4.572" y2="5.334" width="0.127" layer="94"/>
<wire x1="4.572" y1="3.556" x2="4.572" y2="4.064" width="0.127" layer="94"/>
<wire x1="4.572" y1="2.286" x2="4.572" y2="2.794" width="0.127" layer="94"/>
<wire x1="4.572" y1="1.016" x2="4.572" y2="1.524" width="0.127" layer="94"/>
<wire x1="4.572" y1="-0.254" x2="4.572" y2="0.254" width="0.127" layer="94"/>
<wire x1="4.572" y1="-1.524" x2="4.572" y2="-1.016" width="0.127" layer="94"/>
<wire x1="-1.016" y1="-10.16" x2="-1.651" y2="-10.16" width="0.127" layer="94"/>
<wire x1="0.254" y1="-10.16" x2="-0.381" y2="-10.16" width="0.127" layer="94"/>
<wire x1="1.524" y1="-10.16" x2="0.889" y2="-10.16" width="0.127" layer="94"/>
<wire x1="2.794" y1="-10.16" x2="2.159" y2="-10.16" width="0.127" layer="94"/>
<wire x1="4.064" y1="-10.16" x2="3.429" y2="-10.16" width="0.127" layer="94"/>
<wire x1="-3.556" y1="11.43" x2="-4.191" y2="11.43" width="0.127" layer="94"/>
<wire x1="-2.286" y1="11.43" x2="-2.921" y2="11.43" width="0.127" layer="94"/>
<wire x1="-1.016" y1="11.43" x2="-1.651" y2="11.43" width="0.127" layer="94"/>
<wire x1="0.254" y1="11.43" x2="-0.381" y2="11.43" width="0.127" layer="94"/>
<wire x1="1.524" y1="11.43" x2="0.889" y2="11.43" width="0.127" layer="94"/>
<wire x1="2.794" y1="11.43" x2="2.159" y2="11.43" width="0.127" layer="94"/>
<wire x1="3.556" y1="11.43" x2="4.191" y2="11.43" width="0.127" layer="94"/>
<wire x1="-3.556" y1="10.668" x2="-5.08" y2="10.668" width="0.254" layer="94"/>
<wire x1="-5.08" y1="10.668" x2="-5.08" y2="9.652" width="0.254" layer="94"/>
<wire x1="-5.08" y1="9.652" x2="-3.556" y2="9.652" width="0.254" layer="94"/>
<wire x1="-3.556" y1="8.128" x2="-5.08" y2="8.128" width="0.254" layer="94"/>
<wire x1="-5.08" y1="8.128" x2="-5.08" y2="7.112" width="0.254" layer="94"/>
<wire x1="-5.08" y1="7.112" x2="-3.556" y2="7.112" width="0.254" layer="94"/>
<wire x1="-3.556" y1="5.588" x2="-5.08" y2="5.588" width="0.254" layer="94"/>
<wire x1="-5.08" y1="5.588" x2="-5.08" y2="4.572" width="0.254" layer="94"/>
<wire x1="-5.08" y1="4.572" x2="-3.556" y2="4.572" width="0.254" layer="94"/>
<wire x1="-3.556" y1="3.048" x2="-5.08" y2="3.048" width="0.254" layer="94"/>
<wire x1="-5.08" y1="3.048" x2="-5.08" y2="2.032" width="0.254" layer="94"/>
<wire x1="-5.08" y1="2.032" x2="-3.556" y2="2.032" width="0.254" layer="94"/>
<wire x1="-3.556" y1="0.508" x2="-5.08" y2="0.508" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0.508" x2="-5.08" y2="-0.508" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-0.508" x2="-3.556" y2="-0.508" width="0.254" layer="94"/>
<wire x1="-3.556" y1="-2.032" x2="-5.08" y2="-2.032" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.032" x2="-5.08" y2="-3.048" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-3.048" x2="-3.556" y2="-3.048" width="0.254" layer="94"/>
<wire x1="-1.651" y1="-1.524" x2="0.889" y2="-1.524" width="0.1998" layer="94"/>
<wire x1="0.889" y1="-1.524" x2="0.889" y2="0.254" width="0.1998" layer="94"/>
<wire x1="0.889" y1="0.254" x2="1.905" y2="0.254" width="0.1998" layer="94"/>
<wire x1="1.905" y1="0.254" x2="1.905" y2="2.286" width="0.1998" layer="94"/>
<wire x1="1.905" y1="2.286" x2="0.889" y2="2.286" width="0.1998" layer="94"/>
<wire x1="0.889" y1="2.286" x2="0.889" y2="4.064" width="0.1998" layer="94"/>
<wire x1="0.889" y1="4.064" x2="-1.651" y2="4.064" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="4.064" x2="-1.651" y2="3.048" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="3.048" x2="-1.651" y2="2.54" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="2.54" x2="-1.651" y2="2.032" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="2.032" x2="-1.651" y2="1.524" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="1.524" x2="-1.651" y2="1.016" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="1.016" x2="-1.651" y2="0.508" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="0.508" x2="-1.651" y2="0" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="0" x2="-1.651" y2="-0.508" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="-0.508" x2="-1.651" y2="-1.524" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="3.048" x2="-0.889" y2="3.048" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="2.54" x2="-0.889" y2="2.54" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="2.032" x2="-0.889" y2="2.032" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="1.524" x2="-0.889" y2="1.524" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="1.016" x2="-0.889" y2="1.016" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="0.508" x2="-0.889" y2="0.508" width="0.1998" layer="94"/>
<wire x1="-3.556" y1="-4.572" x2="-5.08" y2="-4.572" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-4.572" x2="-5.08" y2="-5.588" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-5.588" x2="-3.556" y2="-5.588" width="0.254" layer="94"/>
<wire x1="-3.556" y1="-7.112" x2="-5.08" y2="-7.112" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.112" x2="-5.08" y2="-8.128" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-8.128" x2="-3.556" y2="-8.128" width="0.254" layer="94"/>
<wire x1="-1.651" y1="0" x2="-0.889" y2="0" width="0.1998" layer="94"/>
<wire x1="-1.651" y1="-0.508" x2="-0.889" y2="-0.508" width="0.1998" layer="94"/>
<wire x1="-5.461" y1="-3.048" x2="-5.461" y2="-4.572" width="0.127" layer="94"/>
<wire x1="-5.461" y1="-5.588" x2="-5.461" y2="-7.112" width="0.127" layer="94"/>
<wire x1="4.572" y1="-2.794" x2="4.572" y2="-2.286" width="0.127" layer="94"/>
<wire x1="4.572" y1="-4.064" x2="4.572" y2="-3.556" width="0.127" layer="94"/>
<wire x1="4.572" y1="-5.334" x2="4.572" y2="-4.826" width="0.127" layer="94"/>
<wire x1="4.572" y1="-6.604" x2="4.572" y2="-6.096" width="0.127" layer="94"/>
<wire x1="4.572" y1="-7.874" x2="4.572" y2="-7.366" width="0.127" layer="94"/>
<wire x1="4.572" y1="-9.144" x2="4.572" y2="-8.636" width="0.127" layer="94"/>
<text x="-5.08" y="11.684" size="1.778" layer="95">&gt;NAME</text>
<text x="7.62" y="-10.16" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="S@2" x="-2.54" y="-12.7" visible="off" length="short" direction="pas" swaplevel="2" rot="R90"/>
<pin name="S@1" x="-5.08" y="-12.7" visible="off" length="short" direction="pas" swaplevel="2" rot="R90"/>
<pin name="S@3" x="0" y="-12.7" visible="off" length="short" direction="pas" swaplevel="2" rot="R90"/>
<pin name="S@4" x="2.54" y="-12.7" visible="off" length="short" direction="pas" swaplevel="2" rot="R90"/>
<pin name="1" x="-7.62" y="10.16" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="-7.62" y="7.62" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="3" x="-7.62" y="5.08" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="4" x="-7.62" y="2.54" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="5" x="-7.62" y="0" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="6" x="-7.62" y="-2.54" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="7" x="-7.62" y="-5.08" visible="pad" length="short" direction="pas" swaplevel="1"/>
<pin name="8" x="-7.62" y="-7.62" visible="pad" length="short" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RJ45*2" prefix="X">
<description>&lt;b&gt;RJ45 Low Profile&lt;/b&gt; Shield Type 2&lt;p&gt;
For all RJ45 L, LC, LCT and X Series Models&lt;br&gt;
Source: www.tycoelectronics.com .. ENG_DS_1654001_1099_RJ_L_0507.pdf</description>
<gates>
<gate name="G$1" symbol="JACK8SHILED4" x="0" y="0"/>
</gates>
<devices>
<device name="-S" package="RJ45-SHIELD2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="S@1" pad="S1"/>
<connect gate="G$1" pin="S@2" pad="S2"/>
<connect gate="G$1" pin="S@3" pad="S3"/>
<connect gate="G$1" pin="S@4" pad="S4"/>
</connects>
<technologies>
<technology name="-6L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="RJ45-6L2-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="16R6097" constant="no"/>
</technology>
<technology name="-6LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="RJ45-6LC2-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="16R6095" constant="no"/>
</technology>
<technology name="-6LCT">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8L">
<attribute name="MF" value="TYCO ELECTRONICS" constant="no"/>
<attribute name="MPN" value="RJ45-8L2-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="52K4446" constant="no"/>
</technology>
<technology name="-8LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="RJ45-8LC2-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="16R6099" constant="no"/>
</technology>
<technology name="-8LCT">
<attribute name="MF" value="TYCO ELECTRONICS" constant="no"/>
<attribute name="MPN" value="RJ45-8LCT2-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="84K0524" constant="no"/>
</technology>
</technologies>
</device>
<device name="-B" package="RJ45-SHIELD2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="S@1" pad="S1"/>
<connect gate="G$1" pin="S@2" pad="S2"/>
<connect gate="G$1" pin="S@3" pad="S3"/>
<connect gate="G$1" pin="S@4" pad="S4"/>
</connects>
<technologies>
<technology name="-6L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="RJ45-6L2-B" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="16R6096" constant="no"/>
</technology>
<technology name="-6LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="RJ45-6LC2-B" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="16R6094" constant="no"/>
</technology>
<technology name="-8L">
<attribute name="MF" value="TYCO ELECTRONICS" constant="no"/>
<attribute name="MPN" value="RJ45-8L2-B" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="52K3810" constant="no"/>
</technology>
<technology name="-8LC">
<attribute name="MF" value="TYCO ELECTRONICS" constant="no"/>
<attribute name="MPN" value="RJ45-8LC2-B." constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="50F1338" constant="no"/>
</technology>
<technology name="-8LCT">
<attribute name="MF" value="TYCO ELECTRONICS" constant="no"/>
<attribute name="MPN" value="RJ45-8LCT2-B" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="91F7263" constant="no"/>
</technology>
</technologies>
</device>
<device name="1-S" package="RJ45-SHIELD1">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="S@1" pad="S1"/>
<connect gate="G$1" pin="S@2" pad="S2"/>
<connect gate="G$1" pin="S@3" pad="S3"/>
<connect gate="G$1" pin="S@4" pad="S4"/>
</connects>
<technologies>
<technology name="-6L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-6LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8LCT">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="1-B" package="RJ45-SHIELD1">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="S@1" pad="S1"/>
<connect gate="G$1" pin="S@2" pad="S2"/>
<connect gate="G$1" pin="S@3" pad="S3"/>
<connect gate="G$1" pin="S@4" pad="S4"/>
</connects>
<technologies>
<technology name="-6L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-6LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8L">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8LC">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
<technology name="-8LCT">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
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
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="X1" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X2" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X3" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X4" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X5" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X6" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X7" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
<part name="X8" library="con-tycoelectronics" deviceset="RJ45*2" device="1-B" technology="-6L"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="X1" gate="G$1" x="17.78" y="53.34" rot="R90"/>
<instance part="X2" gate="G$1" x="55.88" y="53.34" rot="R90"/>
<instance part="X3" gate="G$1" x="88.9" y="53.34" rot="R90"/>
<instance part="X4" gate="G$1" x="119.38" y="53.34" rot="R90"/>
<instance part="X5" gate="G$1" x="149.86" y="53.34" rot="R90"/>
<instance part="X6" gate="G$1" x="180.34" y="53.34" rot="R90"/>
<instance part="X7" gate="G$1" x="210.82" y="53.34" rot="R90"/>
<instance part="X8" gate="G$1" x="241.3" y="53.34" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="1"/>
<wire x1="7.62" y1="45.72" x2="7.62" y2="40.64" width="0.1524" layer="91"/>
<wire x1="7.62" y1="40.64" x2="45.72" y2="40.64" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="1"/>
<wire x1="45.72" y1="40.64" x2="78.74" y2="40.64" width="0.1524" layer="91"/>
<wire x1="78.74" y1="40.64" x2="109.22" y2="40.64" width="0.1524" layer="91"/>
<wire x1="109.22" y1="40.64" x2="109.22" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="1"/>
<wire x1="45.72" y1="45.72" x2="45.72" y2="40.64" width="0.1524" layer="91"/>
<junction x="45.72" y="40.64"/>
<pinref part="X3" gate="G$1" pin="1"/>
<wire x1="78.74" y1="45.72" x2="78.74" y2="40.64" width="0.1524" layer="91"/>
<junction x="78.74" y="40.64"/>
<pinref part="X8" gate="G$1" pin="1"/>
<wire x1="109.22" y1="40.64" x2="139.7" y2="40.64" width="0.1524" layer="91"/>
<wire x1="139.7" y1="40.64" x2="170.18" y2="40.64" width="0.1524" layer="91"/>
<wire x1="170.18" y1="40.64" x2="200.66" y2="40.64" width="0.1524" layer="91"/>
<wire x1="200.66" y1="40.64" x2="231.14" y2="40.64" width="0.1524" layer="91"/>
<wire x1="231.14" y1="40.64" x2="231.14" y2="45.72" width="0.1524" layer="91"/>
<junction x="109.22" y="40.64"/>
<pinref part="X5" gate="G$1" pin="1"/>
<wire x1="139.7" y1="45.72" x2="139.7" y2="40.64" width="0.1524" layer="91"/>
<junction x="139.7" y="40.64"/>
<pinref part="X6" gate="G$1" pin="1"/>
<wire x1="170.18" y1="45.72" x2="170.18" y2="40.64" width="0.1524" layer="91"/>
<junction x="170.18" y="40.64"/>
<pinref part="X7" gate="G$1" pin="1"/>
<wire x1="200.66" y1="45.72" x2="200.66" y2="40.64" width="0.1524" layer="91"/>
<junction x="200.66" y="40.64"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="2"/>
<wire x1="10.16" y1="45.72" x2="10.16" y2="38.1" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="2"/>
<wire x1="10.16" y1="38.1" x2="48.26" y2="38.1" width="0.1524" layer="91"/>
<wire x1="48.26" y1="38.1" x2="81.28" y2="38.1" width="0.1524" layer="91"/>
<wire x1="81.28" y1="38.1" x2="111.76" y2="38.1" width="0.1524" layer="91"/>
<wire x1="111.76" y1="38.1" x2="111.76" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="2"/>
<wire x1="48.26" y1="45.72" x2="48.26" y2="38.1" width="0.1524" layer="91"/>
<junction x="48.26" y="38.1"/>
<pinref part="X3" gate="G$1" pin="2"/>
<wire x1="81.28" y1="45.72" x2="81.28" y2="38.1" width="0.1524" layer="91"/>
<junction x="81.28" y="38.1"/>
<pinref part="X8" gate="G$1" pin="2"/>
<wire x1="111.76" y1="38.1" x2="142.24" y2="38.1" width="0.1524" layer="91"/>
<wire x1="142.24" y1="38.1" x2="172.72" y2="38.1" width="0.1524" layer="91"/>
<wire x1="172.72" y1="38.1" x2="203.2" y2="38.1" width="0.1524" layer="91"/>
<wire x1="203.2" y1="38.1" x2="233.68" y2="38.1" width="0.1524" layer="91"/>
<wire x1="233.68" y1="38.1" x2="233.68" y2="45.72" width="0.1524" layer="91"/>
<junction x="111.76" y="38.1"/>
<pinref part="X5" gate="G$1" pin="2"/>
<wire x1="142.24" y1="45.72" x2="142.24" y2="38.1" width="0.1524" layer="91"/>
<junction x="142.24" y="38.1"/>
<pinref part="X6" gate="G$1" pin="2"/>
<wire x1="172.72" y1="45.72" x2="172.72" y2="38.1" width="0.1524" layer="91"/>
<junction x="172.72" y="38.1"/>
<pinref part="X7" gate="G$1" pin="2"/>
<wire x1="203.2" y1="45.72" x2="203.2" y2="38.1" width="0.1524" layer="91"/>
<junction x="203.2" y="38.1"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="3"/>
<wire x1="12.7" y1="45.72" x2="12.7" y2="35.56" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="3"/>
<wire x1="12.7" y1="35.56" x2="50.8" y2="35.56" width="0.1524" layer="91"/>
<wire x1="50.8" y1="35.56" x2="83.82" y2="35.56" width="0.1524" layer="91"/>
<wire x1="83.82" y1="35.56" x2="114.3" y2="35.56" width="0.1524" layer="91"/>
<wire x1="114.3" y1="35.56" x2="114.3" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="3"/>
<wire x1="50.8" y1="45.72" x2="50.8" y2="35.56" width="0.1524" layer="91"/>
<junction x="50.8" y="35.56"/>
<pinref part="X3" gate="G$1" pin="3"/>
<wire x1="83.82" y1="45.72" x2="83.82" y2="35.56" width="0.1524" layer="91"/>
<junction x="83.82" y="35.56"/>
<pinref part="X8" gate="G$1" pin="3"/>
<wire x1="114.3" y1="35.56" x2="144.78" y2="35.56" width="0.1524" layer="91"/>
<wire x1="144.78" y1="35.56" x2="175.26" y2="35.56" width="0.1524" layer="91"/>
<wire x1="175.26" y1="35.56" x2="205.74" y2="35.56" width="0.1524" layer="91"/>
<wire x1="205.74" y1="35.56" x2="236.22" y2="35.56" width="0.1524" layer="91"/>
<wire x1="236.22" y1="35.56" x2="236.22" y2="45.72" width="0.1524" layer="91"/>
<junction x="114.3" y="35.56"/>
<pinref part="X5" gate="G$1" pin="3"/>
<wire x1="144.78" y1="45.72" x2="144.78" y2="35.56" width="0.1524" layer="91"/>
<junction x="144.78" y="35.56"/>
<pinref part="X6" gate="G$1" pin="3"/>
<wire x1="175.26" y1="45.72" x2="175.26" y2="35.56" width="0.1524" layer="91"/>
<junction x="175.26" y="35.56"/>
<pinref part="X7" gate="G$1" pin="3"/>
<wire x1="205.74" y1="45.72" x2="205.74" y2="35.56" width="0.1524" layer="91"/>
<junction x="205.74" y="35.56"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="4"/>
<wire x1="15.24" y1="45.72" x2="15.24" y2="33.02" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="4"/>
<wire x1="15.24" y1="33.02" x2="53.34" y2="33.02" width="0.1524" layer="91"/>
<wire x1="53.34" y1="33.02" x2="86.36" y2="33.02" width="0.1524" layer="91"/>
<wire x1="86.36" y1="33.02" x2="116.84" y2="33.02" width="0.1524" layer="91"/>
<wire x1="116.84" y1="33.02" x2="116.84" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="4"/>
<wire x1="53.34" y1="45.72" x2="53.34" y2="33.02" width="0.1524" layer="91"/>
<junction x="53.34" y="33.02"/>
<pinref part="X3" gate="G$1" pin="4"/>
<wire x1="86.36" y1="45.72" x2="86.36" y2="33.02" width="0.1524" layer="91"/>
<junction x="86.36" y="33.02"/>
<pinref part="X8" gate="G$1" pin="4"/>
<wire x1="116.84" y1="33.02" x2="147.32" y2="33.02" width="0.1524" layer="91"/>
<wire x1="147.32" y1="33.02" x2="177.8" y2="33.02" width="0.1524" layer="91"/>
<wire x1="177.8" y1="33.02" x2="208.28" y2="33.02" width="0.1524" layer="91"/>
<wire x1="208.28" y1="33.02" x2="238.76" y2="33.02" width="0.1524" layer="91"/>
<wire x1="238.76" y1="33.02" x2="238.76" y2="45.72" width="0.1524" layer="91"/>
<junction x="116.84" y="33.02"/>
<pinref part="X5" gate="G$1" pin="4"/>
<wire x1="147.32" y1="45.72" x2="147.32" y2="33.02" width="0.1524" layer="91"/>
<junction x="147.32" y="33.02"/>
<pinref part="X6" gate="G$1" pin="4"/>
<wire x1="177.8" y1="45.72" x2="177.8" y2="33.02" width="0.1524" layer="91"/>
<junction x="177.8" y="33.02"/>
<pinref part="X7" gate="G$1" pin="4"/>
<wire x1="208.28" y1="45.72" x2="208.28" y2="33.02" width="0.1524" layer="91"/>
<junction x="208.28" y="33.02"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="5"/>
<wire x1="17.78" y1="45.72" x2="17.78" y2="30.48" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="5"/>
<wire x1="17.78" y1="30.48" x2="55.88" y2="30.48" width="0.1524" layer="91"/>
<wire x1="55.88" y1="30.48" x2="88.9" y2="30.48" width="0.1524" layer="91"/>
<wire x1="88.9" y1="30.48" x2="119.38" y2="30.48" width="0.1524" layer="91"/>
<wire x1="119.38" y1="30.48" x2="119.38" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="5"/>
<wire x1="55.88" y1="45.72" x2="55.88" y2="30.48" width="0.1524" layer="91"/>
<junction x="55.88" y="30.48"/>
<pinref part="X3" gate="G$1" pin="5"/>
<wire x1="88.9" y1="45.72" x2="88.9" y2="30.48" width="0.1524" layer="91"/>
<junction x="88.9" y="30.48"/>
<pinref part="X8" gate="G$1" pin="5"/>
<wire x1="119.38" y1="30.48" x2="149.86" y2="30.48" width="0.1524" layer="91"/>
<wire x1="149.86" y1="30.48" x2="180.34" y2="30.48" width="0.1524" layer="91"/>
<wire x1="180.34" y1="30.48" x2="210.82" y2="30.48" width="0.1524" layer="91"/>
<wire x1="210.82" y1="30.48" x2="241.3" y2="30.48" width="0.1524" layer="91"/>
<wire x1="241.3" y1="30.48" x2="241.3" y2="45.72" width="0.1524" layer="91"/>
<junction x="119.38" y="30.48"/>
<pinref part="X5" gate="G$1" pin="5"/>
<wire x1="149.86" y1="45.72" x2="149.86" y2="30.48" width="0.1524" layer="91"/>
<junction x="149.86" y="30.48"/>
<pinref part="X6" gate="G$1" pin="5"/>
<wire x1="180.34" y1="45.72" x2="180.34" y2="30.48" width="0.1524" layer="91"/>
<junction x="180.34" y="30.48"/>
<pinref part="X7" gate="G$1" pin="5"/>
<wire x1="210.82" y1="45.72" x2="210.82" y2="30.48" width="0.1524" layer="91"/>
<junction x="210.82" y="30.48"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="6"/>
<wire x1="20.32" y1="45.72" x2="20.32" y2="27.94" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="6"/>
<wire x1="20.32" y1="27.94" x2="58.42" y2="27.94" width="0.1524" layer="91"/>
<wire x1="58.42" y1="27.94" x2="91.44" y2="27.94" width="0.1524" layer="91"/>
<wire x1="91.44" y1="27.94" x2="121.92" y2="27.94" width="0.1524" layer="91"/>
<wire x1="121.92" y1="27.94" x2="121.92" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="6"/>
<wire x1="58.42" y1="45.72" x2="58.42" y2="27.94" width="0.1524" layer="91"/>
<junction x="58.42" y="27.94"/>
<pinref part="X3" gate="G$1" pin="6"/>
<wire x1="91.44" y1="45.72" x2="91.44" y2="27.94" width="0.1524" layer="91"/>
<junction x="91.44" y="27.94"/>
<pinref part="X8" gate="G$1" pin="6"/>
<wire x1="121.92" y1="27.94" x2="152.4" y2="27.94" width="0.1524" layer="91"/>
<wire x1="152.4" y1="27.94" x2="182.88" y2="27.94" width="0.1524" layer="91"/>
<wire x1="182.88" y1="27.94" x2="213.36" y2="27.94" width="0.1524" layer="91"/>
<wire x1="213.36" y1="27.94" x2="243.84" y2="27.94" width="0.1524" layer="91"/>
<wire x1="243.84" y1="27.94" x2="243.84" y2="45.72" width="0.1524" layer="91"/>
<junction x="121.92" y="27.94"/>
<pinref part="X5" gate="G$1" pin="6"/>
<wire x1="152.4" y1="45.72" x2="152.4" y2="27.94" width="0.1524" layer="91"/>
<junction x="152.4" y="27.94"/>
<pinref part="X6" gate="G$1" pin="6"/>
<wire x1="182.88" y1="45.72" x2="182.88" y2="27.94" width="0.1524" layer="91"/>
<junction x="182.88" y="27.94"/>
<pinref part="X7" gate="G$1" pin="6"/>
<wire x1="213.36" y1="45.72" x2="213.36" y2="27.94" width="0.1524" layer="91"/>
<junction x="213.36" y="27.94"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="7"/>
<wire x1="22.86" y1="45.72" x2="22.86" y2="25.4" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="7"/>
<wire x1="22.86" y1="25.4" x2="60.96" y2="25.4" width="0.1524" layer="91"/>
<wire x1="60.96" y1="25.4" x2="93.98" y2="25.4" width="0.1524" layer="91"/>
<wire x1="93.98" y1="25.4" x2="124.46" y2="25.4" width="0.1524" layer="91"/>
<wire x1="124.46" y1="25.4" x2="124.46" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="7"/>
<wire x1="60.96" y1="45.72" x2="60.96" y2="25.4" width="0.1524" layer="91"/>
<junction x="60.96" y="25.4"/>
<pinref part="X3" gate="G$1" pin="7"/>
<wire x1="93.98" y1="45.72" x2="93.98" y2="25.4" width="0.1524" layer="91"/>
<junction x="93.98" y="25.4"/>
<pinref part="X8" gate="G$1" pin="7"/>
<wire x1="124.46" y1="25.4" x2="154.94" y2="25.4" width="0.1524" layer="91"/>
<wire x1="154.94" y1="25.4" x2="185.42" y2="25.4" width="0.1524" layer="91"/>
<wire x1="185.42" y1="25.4" x2="215.9" y2="25.4" width="0.1524" layer="91"/>
<wire x1="215.9" y1="25.4" x2="246.38" y2="25.4" width="0.1524" layer="91"/>
<wire x1="246.38" y1="25.4" x2="246.38" y2="45.72" width="0.1524" layer="91"/>
<junction x="124.46" y="25.4"/>
<pinref part="X5" gate="G$1" pin="7"/>
<wire x1="154.94" y1="45.72" x2="154.94" y2="25.4" width="0.1524" layer="91"/>
<junction x="154.94" y="25.4"/>
<pinref part="X6" gate="G$1" pin="7"/>
<wire x1="185.42" y1="45.72" x2="185.42" y2="25.4" width="0.1524" layer="91"/>
<junction x="185.42" y="25.4"/>
<pinref part="X7" gate="G$1" pin="7"/>
<wire x1="215.9" y1="45.72" x2="215.9" y2="25.4" width="0.1524" layer="91"/>
<junction x="215.9" y="25.4"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="8"/>
<wire x1="25.4" y1="45.72" x2="25.4" y2="22.86" width="0.1524" layer="91"/>
<pinref part="X4" gate="G$1" pin="8"/>
<wire x1="25.4" y1="22.86" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<wire x1="63.5" y1="22.86" x2="96.52" y2="22.86" width="0.1524" layer="91"/>
<wire x1="96.52" y1="22.86" x2="127" y2="22.86" width="0.1524" layer="91"/>
<wire x1="127" y1="22.86" x2="127" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="8"/>
<wire x1="63.5" y1="45.72" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<junction x="63.5" y="22.86"/>
<pinref part="X3" gate="G$1" pin="8"/>
<wire x1="96.52" y1="45.72" x2="96.52" y2="22.86" width="0.1524" layer="91"/>
<junction x="96.52" y="22.86"/>
<pinref part="X8" gate="G$1" pin="8"/>
<wire x1="127" y1="22.86" x2="157.48" y2="22.86" width="0.1524" layer="91"/>
<wire x1="157.48" y1="22.86" x2="187.96" y2="22.86" width="0.1524" layer="91"/>
<wire x1="187.96" y1="22.86" x2="218.44" y2="22.86" width="0.1524" layer="91"/>
<wire x1="218.44" y1="22.86" x2="248.92" y2="22.86" width="0.1524" layer="91"/>
<wire x1="248.92" y1="22.86" x2="248.92" y2="45.72" width="0.1524" layer="91"/>
<junction x="127" y="22.86"/>
<pinref part="X5" gate="G$1" pin="8"/>
<wire x1="157.48" y1="45.72" x2="157.48" y2="22.86" width="0.1524" layer="91"/>
<junction x="157.48" y="22.86"/>
<pinref part="X6" gate="G$1" pin="8"/>
<wire x1="187.96" y1="45.72" x2="187.96" y2="22.86" width="0.1524" layer="91"/>
<junction x="187.96" y="22.86"/>
<pinref part="X7" gate="G$1" pin="8"/>
<wire x1="218.44" y1="45.72" x2="218.44" y2="22.86" width="0.1524" layer="91"/>
<junction x="218.44" y="22.86"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
