EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 6150 2950 0    50   Input ~ 0
FAN_PWR
$Comp
L power:+5V #PWR0163
U 1 1 5F3D61D4
P 7350 2900
F 0 "#PWR0163" H 7350 2750 50  0001 C CNN
F 1 "+5V" H 7365 3073 50  0000 C CNN
F 2 "" H 7350 2900 50  0001 C CNN
F 3 "" H 7350 2900 50  0001 C CNN
	1    7350 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0164
U 1 1 5F3D61DA
P 7350 3100
F 0 "#PWR0164" H 7350 2850 50  0001 C CNN
F 1 "GND" H 7355 2927 50  0000 C CNN
F 2 "" H 7350 3100 50  0001 C CNN
F 3 "" H 7350 3100 50  0001 C CNN
	1    7350 3100
	1    0    0    -1  
$EndComp
Text GLabel 7350 3000 0    50   Input ~ 0
PEN_PWM
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 5F3D61E1
P 7550 3000
F 0 "J6" H 7630 3042 50  0000 L CNN
F 1 "Conn_01x03" H 7630 2951 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7550 3000 50  0001 C CNN
F 3 "~" H 7550 3000 50  0001 C CNN
	1    7550 3000
	1    0    0    -1  
$EndComp
Text GLabel 3250 450  0    50   Input ~ 0
PEN_PWM
Text GLabel 3500 450  0    50   Input ~ 0
PEN_PWM
Text Notes 5750 2750 0    50   ~ 0
Fan Header
Text Notes 6950 2650 0    50   ~ 0
Pendulum Header
Text Notes 7200 3800 0    50   ~ 0
USART Header
Text GLabel 7650 4150 0    50   Input ~ 0
USART_TX
Text GLabel 7650 4250 0    50   Input ~ 0
USART_RX
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 5F3E867E
P 7850 4150
F 0 "J5" H 7930 4142 50  0000 L CNN
F 1 "Conn_01x04" H 7930 4051 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7850 4150 50  0001 C CNN
F 3 "~" H 7850 4150 50  0001 C CNN
	1    7850 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0165
U 1 1 5F3E9068
P 7650 4350
F 0 "#PWR0165" H 7650 4100 50  0001 C CNN
F 1 "GND" H 7655 4177 50  0000 C CNN
F 2 "" H 7650 4350 50  0001 C CNN
F 3 "" H 7650 4350 50  0001 C CNN
	1    7650 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0166
U 1 1 5F3E96DC
P 7650 4050
F 0 "#PWR0166" H 7650 3900 50  0001 C CNN
F 1 "+5V" H 7665 4223 50  0000 C CNN
F 2 "" H 7650 4050 50  0001 C CNN
F 3 "" H 7650 4050 50  0001 C CNN
	1    7650 4050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5F421C06
P 6350 2950
F 0 "J4" H 6430 2942 50  0000 L CNN
F 1 "Conn_01x02" H 6430 2851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6350 2950 50  0001 C CNN
F 3 "~" H 6350 2950 50  0001 C CNN
	1    6350 2950
	1    0    0    -1  
$EndComp
Text GLabel 6150 3050 0    50   Input ~ 0
FAN_GND
$Comp
L Connector_Generic:Conn_01x04 J9
U 1 1 5F418205
P 8950 4150
F 0 "J9" H 9030 4142 50  0000 L CNN
F 1 "Conn_01x04" H 9030 4051 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8950 4150 50  0001 C CNN
F 3 "~" H 8950 4150 50  0001 C CNN
	1    8950 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0170
U 1 1 5F418D88
P 8750 4050
F 0 "#PWR0170" H 8750 3900 50  0001 C CNN
F 1 "+5V" H 8765 4223 50  0000 C CNN
F 2 "" H 8750 4050 50  0001 C CNN
F 3 "" H 8750 4050 50  0001 C CNN
	1    8750 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0171
U 1 1 5F4191F8
P 8750 4350
F 0 "#PWR0171" H 8750 4100 50  0001 C CNN
F 1 "GND" H 8755 4177 50  0000 C CNN
F 2 "" H 8750 4350 50  0001 C CNN
F 3 "" H 8750 4350 50  0001 C CNN
	1    8750 4350
	1    0    0    -1  
$EndComp
Text GLabel 8750 4150 0    50   Input ~ 0
TRIG
Text GLabel 8750 4250 0    50   Input ~ 0
ECHO
Text Notes 8650 3800 0    50   ~ 0
Ultrasonice Sensor
Text Notes 2500 2750 0    50   ~ 0
LED Driver SEG
Text GLabel 2550 2850 0    50   Input ~ 0
SEG_A
Text GLabel 2550 3050 0    50   Input ~ 0
SEG_B
Text GLabel 2550 3250 0    50   Input ~ 0
SEG_C
Text GLabel 2550 3550 0    50   Input ~ 0
SEG_D
Text GLabel 2550 3350 0    50   Input ~ 0
SEG_E
Text GLabel 2550 2950 0    50   Input ~ 0
SEG_F
Text GLabel 2550 3150 0    50   Input ~ 0
SEG_G
Text GLabel 2550 3450 0    50   Input ~ 0
SEG_DP
Text GLabel 2650 4600 0    50   Input ~ 0
DIG_0
Text GLabel 2650 3900 0    50   Input ~ 0
DIG_1
Text GLabel 2650 4300 0    50   Input ~ 0
DIG_2
Text GLabel 2650 4200 0    50   Input ~ 0
DIG_3
Text GLabel 2650 4500 0    50   Input ~ 0
DIG_4
Text GLabel 2650 4000 0    50   Input ~ 0
DIG_5
Text GLabel 2650 4400 0    50   Input ~ 0
DIG_6
Text GLabel 2650 4100 0    50   Input ~ 0
DIG_7
$Comp
L Connector_Generic:Conn_01x08 J7
U 1 1 5F61580C
P 2850 4200
F 0 "J7" H 2930 4192 50  0000 L CNN
F 1 "Conn_01x08" H 2930 4101 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2850 4200 50  0001 C CNN
F 3 "~" H 2850 4200 50  0001 C CNN
	1    2850 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 5F62F9AB
P 2750 3150
F 0 "J2" H 2830 3142 50  0000 L CNN
F 1 "Conn_01x08" H 2830 3051 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2750 3150 50  0001 C CNN
F 3 "~" H 2750 3150 50  0001 C CNN
	1    2750 3150
	1    0    0    -1  
$EndComp
Text Notes 2500 3800 0    50   ~ 0
LED Driver DIG
Text GLabel 4550 4050 0    50   Input ~ 0
MOSI_5V
Text Notes 3950 3650 0    50   ~ 0
SPI Header
$Comp
L power:GND #PWR0162
U 1 1 5F3106AE
P 3800 3750
F 0 "#PWR0162" H 3800 3500 50  0001 C CNN
F 1 "GND" H 3805 3577 50  0000 C CNN
F 2 "" H 3800 3750 50  0001 C CNN
F 3 "" H 3800 3750 50  0001 C CNN
	1    3800 3750
	1    0    0    -1  
$EndComp
Text GLabel 6400 1950 0    50   Input ~ 0
ADC0
Text GLabel 4550 3950 0    50   Input ~ 0
MISO_5V
Text GLabel 4550 4150 0    50   Input ~ 0
SCK_5V
Text GLabel 6100 4050 0    50   Input ~ 0
MOSI_3V3
Text Notes 5400 3600 0    50   ~ 0
Level Shift Header
$Comp
L power:GND #PWR0146
U 1 1 5F63691A
P 7150 3850
F 0 "#PWR0146" H 7150 3600 50  0001 C CNN
F 1 "GND" H 7155 3677 50  0000 C CNN
F 2 "" H 7150 3850 50  0001 C CNN
F 3 "" H 7150 3850 50  0001 C CNN
	1    7150 3850
	1    0    0    -1  
$EndComp
Text GLabel 6600 4150 2    50   Input ~ 0
MISO_3V3
Text GLabel 6600 4050 2    50   Input ~ 0
SCK_3V3
Text GLabel 6600 3950 2    50   Input ~ 0
RF_EN_3V3
Text GLabel 6100 4150 0    50   Input ~ 0
RF_INT_3V3
Text GLabel 6100 3950 0    50   Input ~ 0
SS_RF_3V3
$Comp
L power:+3.3V #PWR0175
U 1 1 5F67B4B2
P 6100 3850
F 0 "#PWR0175" H 6100 3700 50  0001 C CNN
F 1 "+3.3V" H 6115 4023 50  0000 C CNN
F 2 "" H 6100 3850 50  0001 C CNN
F 3 "" H 6100 3850 50  0001 C CNN
	1    6100 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J12
U 1 1 5F636912
P 6300 3950
F 0 "J12" H 6200 4150 50  0000 L CNN
F 1 "Conn_02x04" H 6380 3851 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x04_P2.54mm_Vertical" H 6300 3950 50  0001 C CNN
F 3 "~" H 6300 3950 50  0001 C CNN
	1    6300 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3850 6600 3850
Text GLabel 4550 4250 0    50   Input ~ 0
SS_SD_CARD_5V
Text GLabel 4800 2950 0    50   Input ~ 0
SPKR_OUT
Text Notes 4400 2750 0    50   ~ 0
Speaker Out
$Comp
L ProjectParts:SJ1-3523N J13
U 1 1 5F71B09B
P 6650 5450
F 0 "J13" H 6250 5800 50  0000 C CNN
F 1 "SJ1-3523N" H 6850 5800 50  0000 C CNN
F 2 "ProjectFootprint:CUI_SJ1-3523N" H 6757 5725 50  0000 C CNN
F 3 "CUI" H 6650 5450 50  0001 L BNN
F 4 "1.02" H 6650 5450 50  0001 L BNN "Field4"
F 5 "Manufacturer recommendation" H 6650 5450 50  0001 L BNN "Field5"
	1    6650 5450
	1    0    0    -1  
$EndComp
Text GLabel 7300 5550 2    50   Input ~ 0
SPKR_OUT
$Comp
L power:GND #PWR0182
U 1 1 5F71B0A3
P 7850 5350
F 0 "#PWR0182" H 7850 5100 50  0001 C CNN
F 1 "GND" H 7855 5177 50  0000 C CNN
F 2 "" H 7850 5350 50  0001 C CNN
F 3 "" H 7850 5350 50  0001 C CNN
	1    7850 5350
	1    0    0    -1  
$EndComp
Text Notes 6200 5000 0    50   ~ 0
Speaker Out 3.5mm
Wire Wire Line
	7250 5450 7250 5550
Wire Wire Line
	7300 5550 7250 5550
Connection ~ 7250 5550
Wire Wire Line
	7250 5350 7850 5350
Wire Wire Line
	3800 3750 4550 3750
$Comp
L power:+5V #PWR0161
U 1 1 5F30FCC3
P 4000 3850
F 0 "#PWR0161" H 4000 3700 50  0001 C CNN
F 1 "+5V" H 4000 4000 50  0000 C CNN
F 2 "" H 4000 3850 50  0001 C CNN
F 3 "" H 4000 3850 50  0001 C CNN
	1    4000 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 3850 4550 3850
Text Notes 4350 1850 0    50   ~ 0
SPI Reset
$Comp
L Connector:Conn_01x02_Female J15
U 1 1 5F7618EC
P 6600 1950
F 0 "J15" H 6628 1926 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6628 1835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 6600 1950 50  0001 C CNN
F 3 "~" H 6600 1950 50  0001 C CNN
	1    6600 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J14
U 1 1 5F7635FB
P 4800 1950
F 0 "J14" H 4828 1926 50  0000 L CNN
F 1 "Conn_01x02_Female" H 4828 1835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 4800 1950 50  0001 C CNN
F 3 "~" H 4800 1950 50  0001 C CNN
	1    4800 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 5F71A68E
P 5000 2950
F 0 "J11" H 5080 2942 50  0000 L CNN
F 1 "Conn_01x02" H 5080 2851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5000 2950 50  0001 C CNN
F 3 "~" H 5000 2950 50  0001 C CNN
	1    5000 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0181
U 1 1 5F71909F
P 4800 3050
F 0 "#PWR0181" H 4800 2800 50  0001 C CNN
F 1 "GND" H 4805 2877 50  0000 C CNN
F 2 "" H 4800 3050 50  0001 C CNN
F 3 "" H 4800 3050 50  0001 C CNN
	1    4800 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0183
U 1 1 5F763C19
P 4600 2050
F 0 "#PWR0183" H 4600 1800 50  0001 C CNN
F 1 "GND" H 4605 1877 50  0000 C CNN
F 2 "" H 4600 2050 50  0001 C CNN
F 3 "" H 4600 2050 50  0001 C CNN
	1    4600 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0184
U 1 1 5F763DF2
P 6400 2050
F 0 "#PWR0184" H 6400 1800 50  0001 C CNN
F 1 "GND" H 6405 1877 50  0000 C CNN
F 2 "" H 6400 2050 50  0001 C CNN
F 3 "" H 6400 2050 50  0001 C CNN
	1    6400 2050
	1    0    0    -1  
$EndComp
Text Notes 6200 1850 0    50   ~ 0
ADC/Ext Int
$Comp
L Connector:Conn_01x06_Female J3
U 1 1 5F765DD4
P 4750 3950
F 0 "J3" H 4778 3926 50  0000 L CNN
F 1 "Conn_01x06_Female" H 4778 3835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 4750 3950 50  0001 C CNN
F 3 "~" H 4750 3950 50  0001 C CNN
	1    4750 3950
	1    0    0    -1  
$EndComp
Text GLabel 4600 1950 0    50   Input ~ 0
RESET
Text GLabel 7850 1950 0    50   Input ~ 0
ADC7
$Comp
L Connector:Conn_01x02_Female J16
U 1 1 5F86355A
P 8050 1950
F 0 "J16" H 8078 1926 50  0000 L CNN
F 1 "Conn_01x02_Female" H 8078 1835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 8050 1950 50  0001 C CNN
F 3 "~" H 8050 1950 50  0001 C CNN
	1    8050 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0185
U 1 1 5F863560
P 7850 2050
F 0 "#PWR0185" H 7850 1800 50  0001 C CNN
F 1 "GND" H 7855 1877 50  0000 C CNN
F 2 "" H 7850 2050 50  0001 C CNN
F 3 "" H 7850 2050 50  0001 C CNN
	1    7850 2050
	1    0    0    -1  
$EndComp
Text Notes 7650 1850 0    50   ~ 0
ADC
Text Notes 8850 2600 0    50   ~ 0
LED
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5F4A1756
P 8950 2950
AR Path="/5F26E841/5F4A1756" Ref="J?"  Part="1" 
AR Path="/5F30B967/5F4A1756" Ref="J10"  Part="1" 
F 0 "J10" H 9058 3231 50  0000 C CNN
F 1 "Conn_01x04_Male" H 9058 3140 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8950 2950 50  0001 C CNN
F 3 "~" H 8950 2950 50  0001 C CNN
	1    8950 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F4A1750
P 9150 3150
AR Path="/5F26E841/5F4A1750" Ref="#PWR?"  Part="1" 
AR Path="/5F30B967/5F4A1750" Ref="#PWR0173"  Part="1" 
F 0 "#PWR0173" H 9150 2900 50  0001 C CNN
F 1 "GND" H 9155 2977 50  0000 C CNN
F 2 "" H 9150 3150 50  0001 C CNN
F 3 "" H 9150 3150 50  0001 C CNN
	1    9150 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4A174A
P 9150 2850
AR Path="/5F26E841/5F4A174A" Ref="#PWR?"  Part="1" 
AR Path="/5F30B967/5F4A174A" Ref="#PWR0172"  Part="1" 
F 0 "#PWR0172" H 9150 2700 50  0001 C CNN
F 1 "+5V" H 9165 3023 50  0000 C CNN
F 2 "" H 9150 2850 50  0001 C CNN
F 3 "" H 9150 2850 50  0001 C CNN
	1    9150 2850
	1    0    0    -1  
$EndComp
Text GLabel 9150 3050 2    50   Output ~ 0
LED_DATA_IN
Text GLabel 9150 2950 2    50   Input ~ 0
LED_DATA_OUT
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J8
U 1 1 5FCEDDF8
P 4600 4950
F 0 "J8" H 4650 5267 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 4650 5176 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 4600 4950 50  0001 C CNN
F 3 "~" H 4600 4950 50  0001 C CNN
	1    4600 4950
	1    0    0    -1  
$EndComp
Text GLabel 4900 4850 2    50   Input ~ 0
MOSI_3V3_2
Text GLabel 4900 4950 2    50   Input ~ 0
MISO_3V3_2
Text GLabel 4900 5050 2    50   Input ~ 0
SCK_3V3_2
$Comp
L power:GND #PWR0210
U 1 1 5FCEFD5F
P 4100 4850
F 0 "#PWR0210" H 4100 4600 50  0001 C CNN
F 1 "GND" H 4105 4677 50  0000 C CNN
F 2 "" H 4100 4850 50  0001 C CNN
F 3 "" H 4100 4850 50  0001 C CNN
	1    4100 4850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 4850 4100 4850
$Comp
L power:+3.3VP #PWR0211
U 1 1 5FCF012F
P 3850 4950
F 0 "#PWR0211" H 4000 4900 50  0001 C CNN
F 1 "+3.3VP" H 3865 5123 50  0000 C CNN
F 2 "" H 3850 4950 50  0001 C CNN
F 3 "" H 3850 4950 50  0001 C CNN
	1    3850 4950
	1    0    0    -1  
$EndComp
Text GLabel 4400 5050 0    50   Input ~ 0
RESET_2
Wire Wire Line
	4400 4950 3850 4950
$EndSCHEMATC
