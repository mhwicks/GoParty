|==================================================================================================|
Sub Locations

	/if (${Zone.ID} == 89) /call SebilisLocs
	/if (${Zone.ID} == 107) /call NurgaLocs
	/if (${Zone.ID} == 208) /call ValorLocs
	/if (${Zone.ID} == 444) /call HillsofShadeLocs
	/if (${Zone.ID} == 73) /call PermafrostLocs
	/if (${Zone.ID} == 59) /call MistmooreLocs
	/if (${Zone.ID} == 418) /call AtiikiLocs
	/if (${Zone.ID} == 457000) /call OldCommonlandsLocsA
	/if (${Zone.ID} == 457) /call OldCommonlandsLocsB
	/if (${Zone.ID} == 467) /call OceangreenVillage
	/if (${Zone.ID} == 485) /call Arthicrex
	/if (${Zone.ID} == 486) /call Foundation
	/if (${Zone.ID} == 700) /call Feerrott2
	/if (${Zone.ID} == 708) /call SanctumSomnium
	/if (${Zone.ID} == 732) /call Erillion
	/if (${Zone.ID} == 764) /call PlaneofShadow
	/if (${Zone.ID} == 780000) /call Katta
	/if (${Zone.ID} == 755) /call eastwasteshard

/return

|Locations
|--------------------------------
	
	|LocDur is how many 6 second Intervals to wait (10 per minute)
	|LocDur IS NOW 1 SECOND INTERVALS! - Any waits over 5 second will wait for 80% mana or better.
	|LocFace is direction - N:0 W:90 S:180 E:270
	|NW:45 SW:135 SE:225 NE:315
	|LocPullRange defaults to 200 unless specifically entered.

|==================================================================================================|
Sub Erillion	
	/echo Loading Erillion, City of Bronze Locations.
	/varset LocationID 732
	/varset intAE 0
	|--------------------------------

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "1"
	/varset LocX[${TotalLocs}] 774
	/varset LocY[${TotalLocs}] 2403
	/varset LocFace[${TotalLocs}] 275
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "1.3"
	/varset LocX[${TotalLocs}] 690
	/varset LocY[${TotalLocs}] 2380
	/varset LocFace[${TotalLocs}] 275
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "1.5"
	/varset LocX[${TotalLocs}] 605
	/varset LocY[${TotalLocs}] 2356
	/varset LocFace[${TotalLocs}] 275
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "1.8"
	/varset LocX[${TotalLocs}] 521
	/varset LocY[${TotalLocs}] 2333
	/varset LocFace[${TotalLocs}] 275
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "2"
	/varset LocX[${TotalLocs}] 436
	/varset LocY[${TotalLocs}] 2309
	/varset LocFace[${TotalLocs}] 275
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "2.5"
	/varset LocX[${TotalLocs}] 118
	/varset LocY[${TotalLocs}] 2249
	/varset LocFace[${TotalLocs}] 315
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "2.8"
	/varset LocX[${TotalLocs}] -192
	/varset LocY[${TotalLocs}] 2262
	/varset LocFace[${TotalLocs}] 270
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "3"
	/varset LocX[${TotalLocs}] -200
	/varset LocY[${TotalLocs}] 2189
	/varset LocFace[${TotalLocs}] 315
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "4"
	/varset LocX[${TotalLocs}] -355
	/varset LocY[${TotalLocs}] 2124
	/varset LocFace[${TotalLocs}] 268
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "5"
	/varset LocX[${TotalLocs}] -453
	/varset LocY[${TotalLocs}] 2125
	/varset LocFace[${TotalLocs}] 265
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "5.5"
	/varset LocX[${TotalLocs}] -683
	/varset LocY[${TotalLocs}] 2037
	/varset LocFace[${TotalLocs}] 295
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "6"
	/varset LocX[${TotalLocs}] -932
	/varset LocY[${TotalLocs}] 1955
	/varset LocFace[${TotalLocs}] 295
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "7"
	/varset LocX[${TotalLocs}] -1220
	/varset LocY[${TotalLocs}] 1913
	/varset LocFace[${TotalLocs}] 213
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "8"
	/varset LocX[${TotalLocs}] -1163
	/varset LocY[${TotalLocs}] 1845
	/varset LocFace[${TotalLocs}] 170
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "9"
	/varset LocX[${TotalLocs}] -960
	/varset LocY[${TotalLocs}] 1585
	/varset LocFace[${TotalLocs}] 180
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "10"
	/varset LocX[${TotalLocs}] -567
	/varset LocY[${TotalLocs}] 1528
	/varset LocFace[${TotalLocs}] 180
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "11"
	/varset LocX[${TotalLocs}] -366
	/varset LocY[${TotalLocs}] 1535
	/varset LocFace[${TotalLocs}] 0
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "12"
	/varset LocX[${TotalLocs}] -237
	/varset LocY[${TotalLocs}] 1551
	/varset LocFace[${TotalLocs}] 144
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "13"
	/varset LocX[${TotalLocs}] -2
	/varset LocY[${TotalLocs}] 1648
	/varset LocFace[${TotalLocs}] 133
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "14"
	/varset LocX[${TotalLocs}] 137
	/varset LocY[${TotalLocs}] 1619
	/varset LocFace[${TotalLocs}] 106
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "14.5"
	/varset LocX[${TotalLocs}] 276
	/varset LocY[${TotalLocs}] 1825
	/varset LocFace[${TotalLocs}] 136
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "15"
	/varset LocX[${TotalLocs}] 414
	/varset LocY[${TotalLocs}] 2031
	/varset LocFace[${TotalLocs}] 136
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "16"
	/varset LocX[${TotalLocs}] 454
	/varset LocY[${TotalLocs}] 2026
	/varset LocFace[${TotalLocs}] 95
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "17"
	/varset LocX[${TotalLocs}] 798
	/varset LocY[${TotalLocs}] 2099
	/varset LocFace[${TotalLocs}] 137
	/varset LocDur[${TotalLocs}] 5
	/varset LocRange[${TotalLocs}] 111

	/varcalc TotalLocs ${TotalLocs} +1
	/varset LocDesc[${TotalLocs}] "17.1"
	/varset LocX[${TotalLocs}] 774
	/varset LocY[${TotalLocs}] 2300
	/varset LocFace[${TotalLocs}] 0
	/varset LocDur[${TotalLocs}] 1
	/varset LocRange[${TotalLocs}] 111

/return
	

|==================================================================================================|
Sub SanctumSomnium	
	/Echo Loading Sanctum Somnium Locations.
	/varset LocationID 708
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "01"
	/Varset LocX[${TotalLocs}] 1659
	/Varset LocY[${TotalLocs}] 198
	/Varset LocFace[${TotalLocs}] 340
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "01b"
	/Varset LocX[${TotalLocs}] 1659
	/Varset LocY[${TotalLocs}] 198
	/Varset LocFace[${TotalLocs}] 340
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 111

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "02"
	/Varset LocX[${TotalLocs}] 1763
	/Varset LocY[${TotalLocs}] 256
	/Varset LocFace[${TotalLocs}] 56
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "03"
	/Varset LocX[${TotalLocs}] 1752
	/Varset LocY[${TotalLocs}] 351
	/Varset LocFace[${TotalLocs}] 313
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "04"
	/Varset LocX[${TotalLocs}] 1772
	/Varset LocY[${TotalLocs}] 447
	/Varset LocFace[${TotalLocs}] 335
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "04b"
	/Varset LocX[${TotalLocs}] 1831
	/Varset LocY[${TotalLocs}] 506
	/Varset LocFace[${TotalLocs}] 335
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "05"
	/Varset LocX[${TotalLocs}] 1890
	/Varset LocY[${TotalLocs}] 565
	/Varset LocFace[${TotalLocs}] 46
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "5.5"
	/Varset LocX[${TotalLocs}] 1946
	/Varset LocY[${TotalLocs}] 533
	/Varset LocFace[${TotalLocs}] 46
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "06"
	/Varset LocX[${TotalLocs}] 2003
	/Varset LocY[${TotalLocs}] 500
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "07"
	/Varset LocX[${TotalLocs}] 2074
	/Varset LocY[${TotalLocs}] 418
	/Varset LocFace[${TotalLocs}] 249
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "7.5"
	/Varset LocX[${TotalLocs}] 1961
	/Varset LocY[${TotalLocs}] 332
	/Varset LocFace[${TotalLocs}] 249
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "08"
	/Varset LocX[${TotalLocs}] 1849
	/Varset LocY[${TotalLocs}] 247
	/Varset LocFace[${TotalLocs}] 216
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "09"
	/Varset LocX[${TotalLocs}] 1954
	/Varset LocY[${TotalLocs}] 186
	/Varset LocFace[${TotalLocs}] 115
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "09.1"
	/Varset LocX[${TotalLocs}] 2009
	/Varset LocY[${TotalLocs}] 167
	/Varset LocFace[${TotalLocs}] 115
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "09b"
	/Varset LocX[${TotalLocs}] 2065
	/Varset LocY[${TotalLocs}] 148
	/Varset LocFace[${TotalLocs}] 115
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "10"
	/Varset LocX[${TotalLocs}] 2177
	/Varset LocY[${TotalLocs}] 110
	/Varset LocFace[${TotalLocs}] 91
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "11"
	/Varset LocX[${TotalLocs}] 2301
	/Varset LocY[${TotalLocs}] 160
	/Varset LocFace[${TotalLocs}] 47
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "12"
| 	/Varset LocX[${TotalLocs}] 2424
| 	/Varset LocY[${TotalLocs}] 272
| 	/Varset LocFace[${TotalLocs}] 326
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "12b"
| 	/Varset LocX[${TotalLocs}] 2394
| 	/Varset LocY[${TotalLocs}] 316
| 	/Varset LocFace[${TotalLocs}] 326
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "13"
| 	/Varset LocX[${TotalLocs}] 2364
| 	/Varset LocY[${TotalLocs}] 360
| 	/Varset LocFace[${TotalLocs}] 326
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "14"
| 	/Varset LocX[${TotalLocs}] 2624
| 	/Varset LocY[${TotalLocs}] 362
| 	/Varset LocFace[${TotalLocs}] 138
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "14b"
| 	/Varset LocX[${TotalLocs}] 2672
| 	/Varset LocY[${TotalLocs}] 338
| 	/Varset LocFace[${TotalLocs}] 138
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "14c"
| 	/Varset LocX[${TotalLocs}] 2720
| 	/Varset LocY[${TotalLocs}] 314
| 	/Varset LocFace[${TotalLocs}] 138
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "15"
| 	/Varset LocX[${TotalLocs}] 2815
| 	/Varset LocY[${TotalLocs}] 267
| 	/Varset LocFace[${TotalLocs}] 219
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "16"
| 	/Varset LocX[${TotalLocs}] 2658
| 	/Varset LocY[${TotalLocs}] 123
| 	/Varset LocFace[${TotalLocs}] 302
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "17"
| 	/Varset LocX[${TotalLocs}] 2544
| 	/Varset LocY[${TotalLocs}] 132
| 	/Varset LocFace[${TotalLocs}] 26
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "18"
| 	/Varset LocX[${TotalLocs}] 2698
| 	/Varset LocY[${TotalLocs}] 103
| 	/Varset LocFace[${TotalLocs}] 226
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
| 	/Varcalc TotalLocs ${TotalLocs} +1
| 	/Varset LocDesc[${TotalLocs}] "19"
| 	/Varset LocX[${TotalLocs}] 2619
| 	/Varset LocY[${TotalLocs}] 47
| 	/Varset LocFace[${TotalLocs}] 236
| 	/Varset LocDur[${TotalLocs}] 5
| 	/Varset LocRange[${TotalLocs}] 111
| 	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "20"
	/Varset LocX[${TotalLocs}] 2347
	/Varset LocY[${TotalLocs}] 70
	/Varset LocFace[${TotalLocs}] 269
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "21"
	/Varset LocX[${TotalLocs}] 2123
	/Varset LocY[${TotalLocs}] 78
	/Varset LocFace[${TotalLocs}] 281
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "22"
	/Varset LocX[${TotalLocs}] 1904
	/Varset LocY[${TotalLocs}] 133
	/Varset LocFace[${TotalLocs}] 226
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "23"
	/Varset LocX[${TotalLocs}] 1726
	/Varset LocY[${TotalLocs}] 190
	/Varset LocFace[${TotalLocs}] 202
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 111
	
	/return

|==================================================================================================|
Sub PlaneofShadow	
	/Echo Loading Plane of Shadow Locations.
	/varset LocationID 764
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1"
	/Varset LocX[${TotalLocs}] 1468
	/Varset LocY[${TotalLocs}] 202
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1.5"
	/Varset LocX[${TotalLocs}] 1506
	/Varset LocY[${TotalLocs}] 165
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "2"
	/Varset LocX[${TotalLocs}] 1545
	/Varset LocY[${TotalLocs}] 129
	/Varset LocFace[${TotalLocs}] 89
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "2.5"
	/Varset LocX[${TotalLocs}] 1610
	/Varset LocY[${TotalLocs}] 97
	/Varset LocFace[${TotalLocs}] 89
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "3"
	/Varset LocX[${TotalLocs}] 1676
	/Varset LocY[${TotalLocs}] 65
	/Varset LocFace[${TotalLocs}] 82
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "3.5"
	/Varset LocX[${TotalLocs}] 1726
	/Varset LocY[${TotalLocs}] 55
	/Varset LocFace[${TotalLocs}] 82
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "4"
	/Varset LocX[${TotalLocs}] 1776
	/Varset LocY[${TotalLocs}] 45
	/Varset LocFace[${TotalLocs}] 32
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "4.5"
	/Varset LocX[${TotalLocs}] 1841
	/Varset LocY[${TotalLocs}] 40
	/Varset LocFace[${TotalLocs}] 32
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "5"
	/Varset LocX[${TotalLocs}] 1906
	/Varset LocY[${TotalLocs}] 36
	/Varset LocFace[${TotalLocs}] 353
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-5"
	/Varset LocX[${TotalLocs}] 1906
	/Varset LocY[${TotalLocs}] 36
	/Varset LocFace[${TotalLocs}] 353
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-4.5"
	/Varset LocX[${TotalLocs}] 1841
	/Varset LocY[${TotalLocs}] 40
	/Varset LocFace[${TotalLocs}] 32
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-4"
	/Varset LocX[${TotalLocs}] 1776
	/Varset LocY[${TotalLocs}] 45
	/Varset LocFace[${TotalLocs}] 32
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-3.5"
	/Varset LocX[${TotalLocs}] 1726
	/Varset LocY[${TotalLocs}] 55
	/Varset LocFace[${TotalLocs}] 82
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-3"
	/Varset LocX[${TotalLocs}] 1676
	/Varset LocY[${TotalLocs}] 65
	/Varset LocFace[${TotalLocs}] 82
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-2.5"
	/Varset LocX[${TotalLocs}] 1610
	/Varset LocY[${TotalLocs}] 97
	/Varset LocFace[${TotalLocs}] 89
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-2"
	/Varset LocX[${TotalLocs}] 1545
	/Varset LocY[${TotalLocs}] 129
	/Varset LocFace[${TotalLocs}] 89
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-1.5"
	/Varset LocX[${TotalLocs}] 1506
	/Varset LocY[${TotalLocs}] 165
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-1"
	/Varset LocX[${TotalLocs}] 1468
	/Varset LocY[${TotalLocs}] 202
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
/return

|==================================================================================================|
Sub Katta	
	/Echo Loading Katta Castrum: Deluge Locations.
	/varset LocationID 780
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Snake Base"
	/Varset LocX[${TotalLocs}] -494
	/Varset LocY[${TotalLocs}] -525
	/Varset LocFace[${TotalLocs}] 282
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Snake Base 2"
	/Varset LocX[${TotalLocs}] -494
	/Varset LocY[${TotalLocs}] -525
	/Varset LocFace[${TotalLocs}] 282
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 90

/return
	
|==================================================================================================|
Sub Foundation	
	/Echo Loading Foundation Locations.
	/varset LocationID 486
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "01"
	/Varset LocX[${TotalLocs}] -1148
	/Varset LocY[${TotalLocs}] 589
	/Varset LocFace[${TotalLocs}] 165
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "02"
	/Varset LocX[${TotalLocs}] -1148
	/Varset LocY[${TotalLocs}] 589
	/Varset LocFace[${TotalLocs}] 165
	/Varset LocDur[${TotalLocs}] 20
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "03"
	/Varset LocX[${TotalLocs}] -1185
	/Varset LocY[${TotalLocs}] 547
	/Varset LocFace[${TotalLocs}] 216
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "04"
	/Varset LocX[${TotalLocs}] -1244
	/Varset LocY[${TotalLocs}] 545
	/Varset LocFace[${TotalLocs}] 230
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "05"
	/Varset LocX[${TotalLocs}] -1354
	/Varset LocY[${TotalLocs}] 461
	/Varset LocFace[${TotalLocs}] 125
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "06"
	/Varset LocX[${TotalLocs}] -1412
	/Varset LocY[${TotalLocs}] 381
	/Varset LocFace[${TotalLocs}] 206
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "07"
	/Varset LocX[${TotalLocs}] -1419
	/Varset LocY[${TotalLocs}] 276
	/Varset LocFace[${TotalLocs}] 112
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "08"
	/Varset LocX[${TotalLocs}] -1401
	/Varset LocY[${TotalLocs}] 182
	/Varset LocFace[${TotalLocs}] 113
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "09"
	/Varset LocX[${TotalLocs}] -1401
	/Varset LocY[${TotalLocs}] 182
	/Varset LocFace[${TotalLocs}] 113
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "10"
	/Varset LocX[${TotalLocs}] -1349
	/Varset LocY[${TotalLocs}] 169
	/Varset LocFace[${TotalLocs}] 103
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "11"
	/Varset LocX[${TotalLocs}] -1343
	/Varset LocY[${TotalLocs}] 134
	/Varset LocFace[${TotalLocs}] 138
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "12"
	/Varset LocX[${TotalLocs}] -1272
	/Varset LocY[${TotalLocs}] 27
	/Varset LocFace[${TotalLocs}] 137
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-11"
	/Varset LocX[${TotalLocs}] -1343
	/Varset LocY[${TotalLocs}] 134
	/Varset LocFace[${TotalLocs}] 138
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-10"
	/Varset LocX[${TotalLocs}] -1349
	/Varset LocY[${TotalLocs}] 169
	/Varset LocFace[${TotalLocs}] 103
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-09"
	/Varset LocX[${TotalLocs}] -1401
	/Varset LocY[${TotalLocs}] 182
	/Varset LocFace[${TotalLocs}] 113
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-08"
	/Varset LocX[${TotalLocs}] -1401
	/Varset LocY[${TotalLocs}] 182
	/Varset LocFace[${TotalLocs}] 113
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-07"
	/Varset LocX[${TotalLocs}] -1419
	/Varset LocY[${TotalLocs}] 276
	/Varset LocFace[${TotalLocs}] 112
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-06"
	/Varset LocX[${TotalLocs}] -1412
	/Varset LocY[${TotalLocs}] 381
	/Varset LocFace[${TotalLocs}] 206
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-05"
	/Varset LocX[${TotalLocs}] -1354
	/Varset LocY[${TotalLocs}] 461
	/Varset LocFace[${TotalLocs}] 125
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-04"
	/Varset LocX[${TotalLocs}] -1244
	/Varset LocY[${TotalLocs}] 545
	/Varset LocFace[${TotalLocs}] 230
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-03"
	/Varset LocX[${TotalLocs}] -1185
	/Varset LocY[${TotalLocs}] 547
	/Varset LocFace[${TotalLocs}] 216
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "-02"
	/Varset LocX[${TotalLocs}] -1148
	/Varset LocY[${TotalLocs}] 589
	/Varset LocFace[${TotalLocs}] 165
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100

/return

|==================================================================================================|
Sub Arthicrex	
	/Echo Loading Arthicrex Locations.
	/varset LocationID 485
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Base"
	/Varset LocY[${TotalLocs}] 519
	/Varset LocX[${TotalLocs}] 590
	/Varset LocFace[${TotalLocs}] 35
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 75
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Base2"
	/Varset LocY[${TotalLocs}] 519
	/Varset LocX[${TotalLocs}] 590
	/Varset LocFace[${TotalLocs}] 317
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 75

/return

|==================================================================================================|
Sub OceangreenVillage	
	/Echo Loading Oceangreen Village Locations.
	/varset LocationID 467
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Near Fellid 1"
	/Varset LocY[${TotalLocs}] -1104
	/Varset LocX[${TotalLocs}] 510
	/Varset LocFace[${TotalLocs}] 336
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Loop 1"
	/Varset LocY[${TotalLocs}] -1074
	/Varset LocX[${TotalLocs}] 406
	/Varset LocFace[${TotalLocs}] 351
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Loop 2"
	/Varset LocY[${TotalLocs}] -967
	/Varset LocX[${TotalLocs}] 317
	/Varset LocFace[${TotalLocs}] 55
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Near Fellid 2"
	/Varset LocY[${TotalLocs}] -1218
	/Varset LocX[${TotalLocs}] 247
	/Varset LocFace[${TotalLocs}] 168
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Loop 3"
	/Varset LocY[${TotalLocs}] -1337
	/Varset LocX[${TotalLocs}] 458
	/Varset LocFace[${TotalLocs}] 6
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Loop 4"
	/Varset LocY[${TotalLocs}] -1001
	/Varset LocX[${TotalLocs}] 627
	/Varset LocFace[${TotalLocs}] 300
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 75

/return

|==================================================================================================|
Sub OldCommonlandsLocsB	
	/Echo Loading OLD COMMONLANDS Locations.
	/varset LocationID 457
	/varset intAE 0
	|Good up to level 95
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lined Up"
	/Varset LocY[${TotalLocs}] 183
	/Varset LocX[${TotalLocs}] -3152
	/Varset LocFace[${TotalLocs}] 272
	/Varset LocDur[${TotalLocs}] 5|30
	/Varset LocRange[${TotalLocs}] 100
	/Varset LocPullRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Angle"
	/Varset LocY[${TotalLocs}] 123
	/Varset LocX[${TotalLocs}] -3195
	/Varset LocFace[${TotalLocs}] 289
	/Varset LocDur[${TotalLocs}] 5|10
	/Varset LocRange[${TotalLocs}] 100
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Side"
	/Varset LocY[${TotalLocs}] 91
	/Varset LocX[${TotalLocs}] -3284
	/Varset LocFace[${TotalLocs}] 329
	/Varset LocDur[${TotalLocs}] 5|10
	/Varset LocRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Back"
	/Varset LocY[${TotalLocs}] 129
	/Varset LocX[${TotalLocs}] -3447
	/Varset LocFace[${TotalLocs}] 61
	/Varset LocDur[${TotalLocs}] 5|10
	/Varset LocRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Back 2"
	/Varset LocY[${TotalLocs}] 199
	/Varset LocX[${TotalLocs}] -3452
	/Varset LocFace[${TotalLocs}] 94
	/Varset LocDur[${TotalLocs}] 5|10
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Side"
	/Varset LocY[${TotalLocs}] 301
	/Varset LocX[${TotalLocs}] -3363
	/Varset LocFace[${TotalLocs}] 160
	/Varset LocDur[${TotalLocs}] 5|10
	/Varset LocRange[${TotalLocs}] 100
	/Varset LocPullRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Angle"
	/Varset LocY[${TotalLocs}] 260
	/Varset LocX[${TotalLocs}] -3231
	/Varset LocFace[${TotalLocs}] 229
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lined Up to Venture Out"
	/Varset LocY[${TotalLocs}] 183
	/Varset LocX[${TotalLocs}] -3152
	/Varset LocFace[${TotalLocs}] 88
	/Varset LocDur[${TotalLocs}] 5|30
	/Varset LocRange[${TotalLocs}] 100
	/Varset LocPullRange[${TotalLocs}] 100

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 1"
	/Varset LocY[${TotalLocs}] 190
	/Varset LocX[${TotalLocs}] -3047
	/Varset LocFace[${TotalLocs}] 92
	/Varset LocDur[${TotalLocs}] 5|20
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 2"
	/Varset LocY[${TotalLocs}] 312
	/Varset LocX[${TotalLocs}] -3013
	/Varset LocFace[${TotalLocs}] 34
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 3"
	/Varset LocY[${TotalLocs}] 400
	/Varset LocX[${TotalLocs}] -2976
	/Varset LocFace[${TotalLocs}] 51
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 4"
	/Varset LocY[${TotalLocs}] 451
	/Varset LocX[${TotalLocs}] -2850
	/Varset LocFace[${TotalLocs}] 46
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Just off Path"
	/Varset LocY[${TotalLocs}] 496
	/Varset LocX[${TotalLocs}] -2682
	/Varset LocFace[${TotalLocs}] 321
	/Varset LocDur[${TotalLocs}] 5|20
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "View Summoners"
	/Varset LocY[${TotalLocs}] 512
	/Varset LocX[${TotalLocs}] -2530
	/Varset LocFace[${TotalLocs}] 94
	/Varset LocDur[${TotalLocs}] 10
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Just off Path Return"
	/Varset LocY[${TotalLocs}] 496
	/Varset LocX[${TotalLocs}] -2682
	/Varset LocFace[${TotalLocs}] 247
	/Varset LocDur[${TotalLocs}] 5|20
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 4 Return"
	/Varset LocY[${TotalLocs}] 451
	/Varset LocX[${TotalLocs}] -2850
	/Varset LocFace[${TotalLocs}] 230
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 3 Return"
	/Varset LocY[${TotalLocs}] 400
	/Varset LocX[${TotalLocs}] -2976
	/Varset LocFace[${TotalLocs}] 203
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 2 Return"
	/Varset LocY[${TotalLocs}] 312
	/Varset LocX[${TotalLocs}] -3047
	/Varset LocFace[${TotalLocs}] 206
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path 1 Return"
	/Varset LocY[${TotalLocs}] 190
	/Varset LocX[${TotalLocs}] -3047
	/Varset LocFace[${TotalLocs}] 263
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	/Varset LocPullRange[${TotalLocs}] 120

/return

|==================================================================================================|
Sub OldCommonladsLocsA
	/Echo Loading OLD COMMONLANDS Locations.
	/varset LocationID 457
	/varset intAE 0
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "SE Corner"
	/Varset LocY[${TotalLocs}] 1015
	/Varset LocX[${TotalLocs}] 1358
	/Varset LocFace[${TotalLocs}] 58
	/Varset LocDur[${TotalLocs}] 225
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "ENE Corner"
	/Varset LocY[${TotalLocs}] 1043
	/Varset LocX[${TotalLocs}] 1376
	/Varset LocFace[${TotalLocs}] 43
	/Varset LocDur[${TotalLocs}] 225
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NE Corner"
	/Varset LocY[${TotalLocs}] 1102
	/Varset LocX[${TotalLocs}] 1413
	/Varset LocFace[${TotalLocs}] 336
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NW Corner"
	/Varset LocY[${TotalLocs}] 1068
	/Varset LocX[${TotalLocs}] 1451
	/Varset LocFace[${TotalLocs}] 11
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "SW Corner"
	/Varset LocY[${TotalLocs}] 972
	/Varset LocX[${TotalLocs}] 1445
	/Varset LocFace[${TotalLocs}] 30
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Going South"
	/Varset LocY[${TotalLocs}] 872
	/Varset LocX[${TotalLocs}] 1380
	/Varset LocFace[${TotalLocs}] 150
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Tip"
	/Varset LocY[${TotalLocs}] 748
	/Varset LocX[${TotalLocs}] 1422
	/Varset LocFace[${TotalLocs}] 150
	/Varset LocDur[${TotalLocs}] 121
	/Varset LocRange[${TotalLocs}] 90

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Was South"
	/Varset LocY[${TotalLocs}] 872
	/Varset LocX[${TotalLocs}] 1380
	/Varset LocFace[${TotalLocs}] 330
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90

/return
	
|==================================================================================================|
Sub AtiikiLocs
	/Echo Loading ATIIKI Locations.
	/varset LocationID 418
	/varset intAE 1
	|--------------------------------

	|Resetting:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Resetting"
	/Varset LocY[${TotalLocs}] -1095
	/Varset LocX[${TotalLocs}] 363
	/Varset LocFace[${TotalLocs}] 47
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "SE Corner"
	/Varset LocY[${TotalLocs}] -1064
	/Varset LocX[${TotalLocs}] 391
	/Varset LocFace[${TotalLocs}] 42
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "East Side - Southern Half"
	/Varset LocY[${TotalLocs}] -898
	/Varset LocX[${TotalLocs}] 367
	/Varset LocFace[${TotalLocs}] 92
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "East Side A"
	/Varset LocY[${TotalLocs}] -826
	/Varset LocX[${TotalLocs}] 273
	/Varset LocFace[${TotalLocs}] 45
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "East Side B"
	/Varset LocY[${TotalLocs}] -661
	/Varset LocX[${TotalLocs}] 296
	/Varset LocFace[${TotalLocs}] 128
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "East Side - Northern Half"
	/Varset LocY[${TotalLocs}] -561
	/Varset LocX[${TotalLocs}] 364
	/Varset LocFace[${TotalLocs}] 91
	/Varset LocDur[${TotalLocs}] 45
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NE Corner"
	/Varset LocY[${TotalLocs}] -445
	/Varset LocX[${TotalLocs}] 409
	/Varset LocFace[${TotalLocs}] 123
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Side - Eastern Half"
	/Varset LocY[${TotalLocs}] -407
	/Varset LocX[${TotalLocs}] 602
	/Varset LocFace[${TotalLocs}] 162
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Side A"
	/Varset LocY[${TotalLocs}] -414
	/Varset LocX[${TotalLocs}] 682
	/Varset LocFace[${TotalLocs}] 80
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Side B"
	/Varset LocY[${TotalLocs}] -321
	/Varset LocX[${TotalLocs}] 757
	/Varset LocFace[${TotalLocs}] 177
	/Varset LocDur[${TotalLocs}] 15
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "North Side - Western Half A"
	/Varset LocY[${TotalLocs}] -416
	/Varset LocX[${TotalLocs}] 874
	/Varset LocFace[${TotalLocs}] 175
	/Varset LocDur[${TotalLocs}] 90
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NW Corner - Avoid the Games A"
	/Varset LocY[${TotalLocs}] -239
	/Varset LocX[${TotalLocs}] 960
	/Varset LocFace[${TotalLocs}] 116
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NW Corner - Avoid the Games B"
	/Varset LocY[${TotalLocs}] -374
	/Varset LocX[${TotalLocs}] 1224
	/Varset LocFace[${TotalLocs}] 194
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "NW Corner - Avoid the Games C"
	/Varset LocY[${TotalLocs}] -579
	/Varset LocX[${TotalLocs}] 1220
	/Varset LocFace[${TotalLocs}] 248
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	|/Varcalc TotalLocs ${TotalLocs} +1
	|/Varset LocDesc[${TotalLocs}] "West Side - Northern Half"
	|/Varset LocY[${TotalLocs}] -554
	|/Varset LocX[${TotalLocs}] 1068
	|/Varset LocFace[${TotalLocs}] 268
	|/Varset LocDur[${TotalLocs}] 5
	|/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "West Side A"
	/Varset LocY[${TotalLocs}] -673
	/Varset LocX[${TotalLocs}] 1124
	/Varset LocFace[${TotalLocs}] 225
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "West Side B"
	/Varset LocY[${TotalLocs}] -762
	/Varset LocX[${TotalLocs}] 1126
	/Varset LocFace[${TotalLocs}] 249
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "West Side - Southern Half"
	/Varset LocY[${TotalLocs}] -930
	/Varset LocX[${TotalLocs}] 1067
	/Varset LocFace[${TotalLocs}] 264
	/Varset LocDur[${TotalLocs}] 90
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "West Side - Southern Half SAFETY ADDITION"
	/Varset LocY[${TotalLocs}] -1047
	/Varset LocX[${TotalLocs}] 1075
	/Varset LocFace[${TotalLocs}] 305
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "SW-ish Corner"
	/Varset LocY[${TotalLocs}] -1109
	/Varset LocX[${TotalLocs}] 941
	/Varset LocFace[${TotalLocs}] 17
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Side - Western Half"
	/Varset LocY[${TotalLocs}] -1103
	/Varset LocX[${TotalLocs}] 874
	/Varset LocFace[${TotalLocs}] 355
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Side A"
	/Varset LocY[${TotalLocs}] -1157
	/Varset LocX[${TotalLocs}] 765
	/Varset LocFace[${TotalLocs}] 333
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Side B"
	/Varset LocY[${TotalLocs}] -1156
	/Varset LocX[${TotalLocs}] 637
	/Varset LocFace[${TotalLocs}] 31
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 95
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "South Side - Eastern Half"
	/Varset LocY[${TotalLocs}] -1099
	/Varset LocX[${TotalLocs}] 568
	/Varset LocFace[${TotalLocs}] 357
	/Varset LocDur[${TotalLocs}] 45
	/Varset LocRange[${TotalLocs}] 90

/return

|==================================================================================================|
Sub MistmooreLocs
	/Echo Loading MISTMOORE Locations.
	/varset LocationID 59
	/varset intAE 1
	|--------------------------------
	
	|Resetting:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Resetting"
	/Varset LocY[${TotalLocs}] -200
	/Varset LocX[${TotalLocs}] -100
	/Varset LocFace[${TotalLocs}] 90
	/Varset LocDur[${TotalLocs}] 50
	/Varset LocRange[${TotalLocs}] 20

/return

|==================================================================================================|
Sub PermafrostLocs
	/Echo Loading PERMAFROST Locations.
	/varset LocationID 73
	/varset intAE 1
	|--------------------------------
	
	|Resetting:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Resetting"
	/Varset LocY[${TotalLocs}] 442
	/Varset LocX[${TotalLocs}] -217
	/Varset LocFace[${TotalLocs}] 315
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 1"
	/Varset LocY[${TotalLocs}] 505
	/Varset LocX[${TotalLocs}] -325
	/Varset LocFace[${TotalLocs}] 315
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 2"
	/Varset LocY[${TotalLocs}] 550
	/Varset LocX[${TotalLocs}] -404
	/Varset LocFace[${TotalLocs}] 350
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 3"
	/Varset LocY[${TotalLocs}] 580
	/Varset LocX[${TotalLocs}] -336
	/Varset LocFace[${TotalLocs}] 45
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 4"
	/Varset LocY[${TotalLocs}] 637
	/Varset LocX[${TotalLocs}] -314
	/Varset LocFace[${TotalLocs}] 45
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 5"
	/Varset LocY[${TotalLocs}] 633
	/Varset LocX[${TotalLocs}] -207
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 6"
	/Varset LocY[${TotalLocs}] 569
	/Varset LocX[${TotalLocs}] -228
	/Varset LocFace[${TotalLocs}] 135
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 7"
	/Varset LocY[${TotalLocs}] 479
	/Varset LocX[${TotalLocs}] -233
	/Varset LocFace[${TotalLocs}] 0
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Route 8"
	/Varset LocY[${TotalLocs}] 463
	/Varset LocX[${TotalLocs}] -176
	/Varset LocFace[${TotalLocs}] 10
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "First Gate"
	/Varset LocY[${TotalLocs}] 433
	/Varset LocX[${TotalLocs}] -217
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past First Gate"
	/Varset LocY[${TotalLocs}] 416
	/Varset LocX[${TotalLocs}] -216
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Second Gate"
	/Varset LocY[${TotalLocs}] 392
	/Varset LocX[${TotalLocs}] -218
	/Varset LocFace[${TotalLocs}] 90
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past Second Gate"
	/Varset LocY[${TotalLocs}] 391
	/Varset LocX[${TotalLocs}] -184
	/Varset LocFace[${TotalLocs}] 90
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 365
	/Varset LocX[${TotalLocs}] -144
	/Varset LocFace[${TotalLocs}] 211
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 266
	/Varset LocX[${TotalLocs}] -193
	/Varset LocFace[${TotalLocs}] 83
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 281
	/Varset LocX[${TotalLocs}] -75
	/Varset LocFace[${TotalLocs}] 133
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Approaching straight walls"
	/Varset LocY[${TotalLocs}] 246
	/Varset LocX[${TotalLocs}] -44
	/Varset LocFace[${TotalLocs}] 88
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Regular Door 1"
	/Varset LocY[${TotalLocs}] 241
	/Varset LocX[${TotalLocs}] -11
	/Varset LocFace[${TotalLocs}] 92
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Closet 1"
	/Varset LocY[${TotalLocs}] 249
	/Varset LocX[${TotalLocs}] 5
	/Varset LocFace[${TotalLocs}] 7
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Inside Closet 1 (A return point)"
	/Varset LocY[${TotalLocs}] 277
	/Varset LocX[${TotalLocs}] 12
	/Varset LocFace[${TotalLocs}] 181
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Closet 1"
	/Varset LocY[${TotalLocs}] 249
	/Varset LocX[${TotalLocs}] 5
	/Varset LocFace[${TotalLocs}] 7
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Regular Door 2"
	/Varset LocY[${TotalLocs}] 242
	/Varset LocX[${TotalLocs}] 23
	/Varset LocFace[${TotalLocs}] 89
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past Regular Door 2"
	/Varset LocY[${TotalLocs}] 246
	/Varset LocX[${TotalLocs}] 46
	/Varset LocFace[${TotalLocs}] 11
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Heading to caves"
	/Varset LocY[${TotalLocs}] 274
	/Varset LocX[${TotalLocs}] 52
	/Varset LocFace[${TotalLocs}] 100
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Heading to caves Door 3"
	/Varset LocY[${TotalLocs}] 257
	/Varset LocX[${TotalLocs}] 104
	/Varset LocFace[${TotalLocs}] 95
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Heading to caves past Door 3"
	/Varset LocY[${TotalLocs}] 267
	/Varset LocX[${TotalLocs}] 137
	/Varset LocFace[${TotalLocs}] 41
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Into Caves (drop here)"
	/Varset LocY[${TotalLocs}] 303
	/Varset LocX[${TotalLocs}] 179
	/Varset LocFace[${TotalLocs}] 41
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Into Caves 2"
	/Varset LocY[${TotalLocs}] 291
	/Varset LocX[${TotalLocs}] 174
	/Varset LocFace[${TotalLocs}] 92
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Into Caves 3"
	/Varset LocY[${TotalLocs}] 286
	/Varset LocX[${TotalLocs}] 206
	/Varset LocFace[${TotalLocs}] 353
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Ramp Shortcut Bottom"
	/Varset LocY[${TotalLocs}] 325
	/Varset LocX[${TotalLocs}] 198
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Clear for Ramp 1"
	/Varset LocY[${TotalLocs}] 357
	/Varset LocX[${TotalLocs}] 204
	/Varset LocFace[${TotalLocs}] 47
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Clear for Ramp 2"
	/Varset LocY[${TotalLocs}] 401
	/Varset LocX[${TotalLocs}] 230
	/Varset LocFace[${TotalLocs}] 291
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Clear for Ramp 3"
	/Varset LocY[${TotalLocs}] 385
	/Varset LocX[${TotalLocs}] 297
	/Varset LocFace[${TotalLocs}] 138
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Clear for Ramp 2"
	/Varset LocY[${TotalLocs}] 401
	/Varset LocX[${TotalLocs}] 230
	/Varset LocFace[${TotalLocs}] 103
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Clear for Ramp 1"
	/Varset LocY[${TotalLocs}] 357
	/Varset LocX[${TotalLocs}] 204
	/Varset LocFace[${TotalLocs}] 195
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Ramp Shortcut Bottom - return point"
	/Varset LocY[${TotalLocs}] 320
	/Varset LocX[${TotalLocs}] 202
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Ramp Shortcut TOP"
	/Varset LocY[${TotalLocs}] 352
	/Varset LocX[${TotalLocs}] 249
	/Varset LocFace[${TotalLocs}] 164
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Upper Hall 1"
	/Varset LocY[${TotalLocs}] 315
	/Varset LocX[${TotalLocs}] 260
	/Varset LocFace[${TotalLocs}] 88
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Upper Hall 2"
	/Varset LocY[${TotalLocs}] 327
	/Varset LocX[${TotalLocs}] 348
	/Varset LocFace[${TotalLocs}] 14
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Upper Hall 3"
	/Varset LocY[${TotalLocs}] 388
	/Varset LocX[${TotalLocs}] 356
	/Varset LocFace[${TotalLocs}] 314
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 40

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Upper Hall 4 (drop here)"
	/Varset LocY[${TotalLocs}] 406
	/Varset LocX[${TotalLocs}] 333
	/Varset LocFace[${TotalLocs}] 40
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Fall to Lower Hall (drop here)"
	/Varset LocY[${TotalLocs}] 457
	/Varset LocX[${TotalLocs}] 356
	/Varset LocFace[${TotalLocs}] 253
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 1"
	/Varset LocY[${TotalLocs}] 444
	/Varset LocX[${TotalLocs}] 292
	/Varset LocFace[${TotalLocs}] 185
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 40

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 2"
	/Varset LocY[${TotalLocs}] 397
	/Varset LocX[${TotalLocs}] 294
	/Varset LocFace[${TotalLocs}] 140
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 3"
	/Varset LocY[${TotalLocs}] 274
	/Varset LocX[${TotalLocs}] 391
	/Varset LocFace[${TotalLocs}] 86
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 4"
	/Varset LocY[${TotalLocs}] 294
	/Varset LocX[${TotalLocs}] 372
	/Varset LocFace[${TotalLocs}] 262
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 5"
	/Varset LocY[${TotalLocs}] 291
	/Varset LocX[${TotalLocs}] 337
	/Varset LocFace[${TotalLocs}] 313
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 4"
	/Varset LocY[${TotalLocs}] 294
	/Varset LocX[${TotalLocs}] 371
	/Varset LocFace[${TotalLocs}] 137
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 3"
	/Varset LocY[${TotalLocs}] 274
	/Varset LocX[${TotalLocs}] 391
	/Varset LocFace[${TotalLocs}] 86
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Snag a Spawn (drop here)"
	/Varset LocY[${TotalLocs}] 275
	/Varset LocX[${TotalLocs}] 428
	/Varset LocFace[${TotalLocs}] 272
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Lower Hall 3"
	/Varset LocY[${TotalLocs}] 274
	/Varset LocX[${TotalLocs}] 391
	/Varset LocFace[${TotalLocs}] 200
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Bottom of long ramp up"
	/Varset LocY[${TotalLocs}] 246
	/Varset LocX[${TotalLocs}] 382
	/Varset LocFace[${TotalLocs}] 178
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Top of long Ramp"
	/Varset LocY[${TotalLocs}] 145
	/Varset LocX[${TotalLocs}] 380
	/Varset LocFace[${TotalLocs}] 291
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Getting out of here!"
	/Varset LocY[${TotalLocs}] 156
	/Varset LocX[${TotalLocs}] 361
	/Varset LocFace[${TotalLocs}] 353
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Getting out of here - Door 1"
	/Varset LocY[${TotalLocs}] 203
	/Varset LocX[${TotalLocs}] 355
	/Varset LocFace[${TotalLocs}] 353
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Getting out of here - Past Door 1"
	/Varset LocY[${TotalLocs}] 230
	/Varset LocX[${TotalLocs}] 347
	/Varset LocFace[${TotalLocs}] 247
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 1"
	/Varset LocY[${TotalLocs}] 189
	/Varset LocX[${TotalLocs}] 281
	/Varset LocFace[${TotalLocs}] 269
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 2"
	/Varset LocY[${TotalLocs}] 206
	/Varset LocX[${TotalLocs}] 240
	/Varset LocFace[${TotalLocs}] 284
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 3"
	/Varset LocY[${TotalLocs}] 224
	/Varset LocX[${TotalLocs}] 198
	/Varset LocFace[${TotalLocs}] 264
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 4"
	/Varset LocY[${TotalLocs}] 212
	/Varset LocX[${TotalLocs}] 160
	/Varset LocFace[${TotalLocs}] 188
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 5"
	/Varset LocY[${TotalLocs}] 185
	/Varset LocX[${TotalLocs}] 157
	/Varset LocFace[${TotalLocs}] 275
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost Out 6"
	/Varset LocY[${TotalLocs}] 189
	/Varset LocX[${TotalLocs}] 103
	/Varset LocFace[${TotalLocs}] 9
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 30

	|Return Point

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Heading to caves Door 3 - (return point)"
	/Varset LocY[${TotalLocs}] 257
	/Varset LocX[${TotalLocs}] 104
	/Varset LocFace[${TotalLocs}] 291
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Heading to caves"
	/Varset LocY[${TotalLocs}] 274
	/Varset LocX[${TotalLocs}] 52
	/Varset LocFace[${TotalLocs}] 183
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past Regular Door 2"
	/Varset LocY[${TotalLocs}] 246
	/Varset LocX[${TotalLocs}] 46
	/Varset LocFace[${TotalLocs}] 267
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Regular Door 2"
	/Varset LocY[${TotalLocs}] 242
	/Varset LocX[${TotalLocs}] 23
	/Varset LocFace[${TotalLocs}] 269
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Closet 1"
	/Varset LocY[${TotalLocs}] 249
	/Varset LocX[${TotalLocs}] 5
	/Varset LocFace[${TotalLocs}] 253
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Regular Door 1"
	/Varset LocY[${TotalLocs}] 241
	/Varset LocX[${TotalLocs}] -11
	/Varset LocFace[${TotalLocs}] 270
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Approaching straight walls"
	/Varset LocY[${TotalLocs}] 246
	/Varset LocX[${TotalLocs}] -44
	/Varset LocFace[${TotalLocs}] 270
	
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 281
	/Varset LocX[${TotalLocs}] -75
	/Varset LocFace[${TotalLocs}] 262
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 266
	/Varset LocX[${TotalLocs}] -193
	/Varset LocFace[${TotalLocs}] 19
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Hall 1 to drops"
	/Varset LocY[${TotalLocs}] 365
	/Varset LocX[${TotalLocs}] -144
	/Varset LocFace[${TotalLocs}] 291
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past Second Gate"
	/Varset LocY[${TotalLocs}] 391
	/Varset LocX[${TotalLocs}] -184
	/Varset LocFace[${TotalLocs}] 270
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Second Gate"
	/Varset LocY[${TotalLocs}] 392
	/Varset LocX[${TotalLocs}] -218
	/Varset LocFace[${TotalLocs}] 270
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Past First Gate"
	/Varset LocY[${TotalLocs}] 416
	/Varset LocX[${TotalLocs}] -216
	/Varset LocFace[${TotalLocs}] 1
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "First Gate"
	/Varset LocY[${TotalLocs}] 433
	/Varset LocX[${TotalLocs}] -217
	/Varset LocFace[${TotalLocs}] 1
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
/return

|==================================================================================================|
Sub	HillsofShadeLocs
	/Echo Loading HILLS OF SHADE Locations.
	/varset LocationID 444
	/varset intAE 1
	|--------------------------------

	|Resetting:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Resetting"
	/Varset LocY[${TotalLocs}] 1454
	/Varset LocX[${TotalLocs}] 12
	/Varset LocFace[${TotalLocs}] 225
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 60
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Main House"
	/Varset LocY[${TotalLocs}] 1454
	/Varset LocX[${TotalLocs}] 12
	/Varset LocFace[${TotalLocs}] 225
	/Varset LocDur[${TotalLocs}] 180
	/Varset LocRange[${TotalLocs}] 60
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path West"
	/Varset LocY[${TotalLocs}] 1538
	/Varset LocX[${TotalLocs}] -29
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "East Hut"
	/Varset LocY[${TotalLocs}] 1535
	/Varset LocX[${TotalLocs}] -261
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 120
	/Varset LocRange[${TotalLocs}] 60
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Path West"
	/Varset LocY[${TotalLocs}] 1538
	/Varset LocX[${TotalLocs}] -29
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 50
	
/return	

|==================================================================================================|
Sub ValorLocs
	/Echo Loading VALOR Locations.
	/varset LocationID 208
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Resetting"
	/Varset LocY[${TotalLocs}] -1574
	/Varset LocX[${TotalLocs}] -1173
	/Varset LocFace[${TotalLocs}] 225
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set One Frog1"
	/Varset LocY[${TotalLocs}] -1725
	/Varset LocX[${TotalLocs}] -1250
	/Varset LocFace[${TotalLocs}] 290
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set One Frog2"
	/Varset LocY[${TotalLocs}] -1613
	/Varset LocX[${TotalLocs}] -1219
	/Varset LocFace[${TotalLocs}] 255
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set One Frog3"
	/Varset LocY[${TotalLocs}] -1536
	/Varset LocX[${TotalLocs}] -1300
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Headed to Set Two"
	/Varset LocY[${TotalLocs}] -1291
	/Varset LocX[${TotalLocs}] -1345
	/Varset LocFace[${TotalLocs}] 355
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set Two Frog1"
	/Varset LocY[${TotalLocs}] -1105
	/Varset LocX[${TotalLocs}] -1321
	/Varset LocFace[${TotalLocs}] 5
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set Two Frog2"
	/Varset LocY[${TotalLocs}] -1101
	/Varset LocX[${TotalLocs}] -1267
	/Varset LocFace[${TotalLocs}] 350
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Set Two Frog3"
	/Varset LocY[${TotalLocs}] -1036
	/Varset LocX[${TotalLocs}] -1201
	/Varset LocFace[${TotalLocs}] 10
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae1"
	/Varset LocY[${TotalLocs}] -1182
	/Varset LocX[${TotalLocs}] -1215
	/Varset LocFace[${TotalLocs}] 70
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae1 - Verify"
	/Varset LocY[${TotalLocs}] -1213
	/Varset LocX[${TotalLocs}] -1130
	/Varset LocFace[${TotalLocs}] 350
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae2"
	/Varset LocY[${TotalLocs}] -901
	/Varset LocX[${TotalLocs}] -1098
	/Varset LocFace[${TotalLocs}] 300
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae2+"
	/Varset LocY[${TotalLocs}] -803
	/Varset LocX[${TotalLocs}] -1150
	/Varset LocFace[${TotalLocs}] 200
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae3 route1"
	/Varset LocY[${TotalLocs}] -1213
	/Varset LocX[${TotalLocs}] -1130
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80
	
	|---------------------------------------------------------Skip Larvae 3 During Fabled:
	|/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae3 route 2"
	/Varset LocY[${TotalLocs}] -1291
	/Varset LocX[${TotalLocs}] -1008
	/Varset LocFace[${TotalLocs}] 45
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 20
	
	|/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae3"
	/Varset LocY[${TotalLocs}] -1249
	/Varset LocX[${TotalLocs}] -967
	/Varset LocFace[${TotalLocs}] 350
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	|---------------------------------------------------------Skip Larvae 3 During Fabled  ^
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae4 route 1"
	/Varset LocY[${TotalLocs}] -1289
	/Varset LocX[${TotalLocs}] -1067
	/Varset LocFace[${TotalLocs}] 160
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 20
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae4"
	/Varset LocY[${TotalLocs}] -1516
	/Varset LocX[${TotalLocs}] -1047
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Bonus Paired Frogs route1"
	/Varset LocY[${TotalLocs}] -1504
	/Varset LocX[${TotalLocs}] -872
	/Varset LocFace[${TotalLocs}] 45
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Bonus Paired Frogs"
	/Varset LocY[${TotalLocs}] -1436
	/Varset LocX[${TotalLocs}] -814
	/Varset LocFace[${TotalLocs}] 80
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Bonus Paired Frogs leaving"
	/Varset LocY[${TotalLocs}] -1504
	/Varset LocX[${TotalLocs}] -872
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae5"
	/Varset LocY[${TotalLocs}] -1699
	/Varset LocX[${TotalLocs}] -868
	/Varset LocFace[${TotalLocs}] 150
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Larvae6"
	/Varset LocY[${TotalLocs}] -1731
	/Varset LocX[${TotalLocs}] -593
	/Varset LocFace[${TotalLocs}] 10
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Back to Larvae5"
	/Varset LocY[${TotalLocs}] -1699
	/Varset LocX[${TotalLocs}] -868
	/Varset LocFace[${TotalLocs}] 150
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Headed back to Set One"
	/Varset LocY[${TotalLocs}] -1687
	/Varset LocX[${TotalLocs}] -1184
	/Varset LocFace[${TotalLocs}] 273
	/Varset LocDur[${TotalLocs}] 1
	/Varset LocRange[${TotalLocs}] 80

/return

|==================================================================================================|
Sub NurgaLocs
	/Echo Loading NURGA Locations.
	/varset LocationID 107
	|--------------------------------

	|Near Z Out:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Near Z Out"
	/Varset LocY[${TotalLocs}] -1028
	/Varset LocX[${TotalLocs}] -832
	/Varset LocFace[${TotalLocs}] 1
	/Varset LocDur[${TotalLocs}] 500
	/Varset LocRange[${TotalLocs}] 100
	
	|To Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "To Z Out Hall"
	/Varset LocY[${TotalLocs}] -1022
	/Varset LocX[${TotalLocs}] -912
	/Varset LocFace[${TotalLocs}] 255
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 115
	|If you make this LocDur REALLY big (like over 200), then you'll stay here all day long.  Normally it's 5.
	
	|Further Down Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Further Down Z Out Hall"
	/Varset LocY[${TotalLocs}] -1090
	/Varset LocX[${TotalLocs}] -960
	/Varset LocFace[${TotalLocs}] 191
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 95
	
	|End of Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "End of Z Out Hall"
	/Varset LocY[${TotalLocs}] -1148
	/varset LocX[${TotalLocs}] -953
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 70
	
	|Just Outside of Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Just Outside of Z Out Hall"
	/Varset LocY[${TotalLocs}] -1230
	/varset LocX[${TotalLocs}] -1000
	/Varset LocFace[${TotalLocs}] 255
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 75
	
	|Two mobs near the start of my old loop:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Two mobs near the start of my old loop"
	/Varset LocY[${TotalLocs}] -1300
	/varset LocX[${TotalLocs}] -975
	/Varset LocFace[${TotalLocs}] 197
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 75
	
	|Rounding first pillar 90:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Rounding first pillar 90"
	/Varset LocY[${TotalLocs}] -1334
	/varset LocX[${TotalLocs}] -1028
	/Varset LocFace[${TotalLocs}] 254
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	|Just South East of first pillar:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Just South East of first pillar"
	/Varset LocY[${TotalLocs}] -1328
	/varset LocX[${TotalLocs}] -1050
	/Varset LocFace[${TotalLocs}] 312
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 80
	
	|East of first Pillar (dangerous):
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Near Z Out"
	/Varset LocY[${TotalLocs}] -1267
	/varset LocX[${TotalLocs}] -1065
	/Varset LocFace[${TotalLocs}] 312
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 70
	
	|Safe spot North of first pillar - pull time!:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Safe spot North of first pillar - pull time!"
	/Varset LocY[${TotalLocs}] -1233
	/varset LocX[${TotalLocs}] -1033
	/Varset LocFace[${TotalLocs}] 76
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	
	|Deep spot North of second pillar - pull time!:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Deep spot North of second pillar - pull time!"
	/Varset LocY[${TotalLocs}] -1211
	/varset LocX[${TotalLocs}] -1122
	/Varset LocFace[${TotalLocs}] 270
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 90
	
	|Safe spot North of first pillar - pull time!:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Safe spot North of first pillar - pull time!"
	/Varset LocY[${TotalLocs}] -1233
	/varset LocX[${TotalLocs}] -1033
	/Varset LocFace[${TotalLocs}] 76
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 120
	
	|Almost back to zout hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Almost back to zout hall"
	/Varset LocY[${TotalLocs}] -1186
	/varset LocX[${TotalLocs}] -980
	/Varset LocFace[${TotalLocs}] 98
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 100
	
	|End of Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "End of Z Out Hall"
	/Varset LocY[${TotalLocs}] -1148
	/varset LocX[${TotalLocs}] -953
	/Varset LocFace[${TotalLocs}] 3
	/Varset LocDur[${TotalLocs}]5
	/Varset LocRange[${TotalLocs}] 70
	
	|Further Down Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Further Down Z Out Hall"
	/Varset LocY[${TotalLocs}] -1090
	/Varset LocX[${TotalLocs}] -960
	/Varset LocFace[${TotalLocs}] 1
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 70
	
	|To Z Out Hall:
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "To Z Out Hall"
	/Varset LocY[${TotalLocs}] -1030
	/Varset LocX[${TotalLocs}] -910
	/Varset LocFace[${TotalLocs}] 269
	/Varset LocDur[${TotalLocs}] 5
	/Varset LocRange[${TotalLocs}] 95

/return

|==================================================================================================|
Sub SebilisLocs
	/Echo Loading SEBILIS Locations.
	/varset LocationID 89
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "A"
	/Varset LocY[${TotalLocs}] -957
	/Varset LocX[${TotalLocs}] 106
	/Varset LocFace[${TotalLocs}] 0
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 55

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "B"
	/Varset LocY[${TotalLocs}] -917
	/Varset LocX[${TotalLocs}] 57
	/Varset LocFace[${TotalLocs}] 90
	/Varset LocDur[${TotalLocs}] 0
	/Varset LocRange[${TotalLocs}] 45

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "C"
	/Varset LocY[${TotalLocs}] -866
	/Varset LocX[${TotalLocs}] 109
	/Varset LocFace[${TotalLocs}] 180
	/Varset LocDur[${TotalLocs}] 0
	/Varset LocRange[${TotalLocs}] 45

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "D"
	/Varset LocY[${TotalLocs}] -919
	/Varset LocX[${TotalLocs}] 160
	/Varset LocFace[${TotalLocs}] 270
	/Varset LocDur[${TotalLocs}] 0
	/Varset LocRange[${TotalLocs}] 45

/return

|==================================================================================================|
Sub Feerrott2
	/Echo Loading Feerrott2 Locations.
	/varset LocationID 700
	|--------------------------------

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "Begin"
	/Varset LocX[${TotalLocs}] -592
	/Varset LocY[${TotalLocs}] -342
	/Varset LocFace[${TotalLocs}] 315
	/Varset LocDur[${TotalLocs}] 60
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1"
	/Varset LocX[${TotalLocs}]  -583
	/Varset LocY[${TotalLocs}] -172
	/Varset LocFace[${TotalLocs}] 225
	/Varset LocDur[${TotalLocs}] 60
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "2"
	/Varset LocX[${TotalLocs}] -359
	/Varset LocY[${TotalLocs}] 30
	/Varset LocFace[${TotalLocs}] 135
	/Varset LocDur[${TotalLocs}] 60
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "3"
	/Varset LocX[${TotalLocs}] -526
	/Varset LocY[${TotalLocs}] -398
	/Varset LocFace[${TotalLocs}] 135
	/Varset LocDur[${TotalLocs}] 60
	/Varset LocRange[${TotalLocs}] 130
/return

|==================================================================================================|
Sub eastwasteshard
	/Echo Loading eastwasteshard Locations.
	/varset LocationID 755
	|--------------------------------
	
	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1"
	/Varset LocX[${TotalLocs}] -2292
	/Varset LocY[${TotalLocs}] 286
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1.1"
	/Varset LocX[${TotalLocs}] -2310
	/Varset LocY[${TotalLocs}] 382
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "2"
	/Varset LocX[${TotalLocs}] -2260
	/Varset LocY[${TotalLocs}] 275
	/Varset LocFace[${TotalLocs}] 370
	/Varset LocDur[${TotalLocs}] 10
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "3"
	/Varset LocX[${TotalLocs}] -2142
	/Varset LocY[${TotalLocs}] 230
	/Varset LocFace[${TotalLocs}] 370
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "4"
	/Varset LocX[${TotalLocs}] -1971
	/Varset LocY[${TotalLocs}] 286
	/Varset LocFace[${TotalLocs}] 0
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "5"
	/Varset LocX[${TotalLocs}] -1859
	/Varset LocY[${TotalLocs}] 310
	/Varset LocFace[${TotalLocs}] 380
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "6"
	/Varset LocX[${TotalLocs}] -1750
	/Varset LocY[${TotalLocs}] 435
	/Varset LocFace[${TotalLocs}] 5
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "7"
	/Varset LocX[${TotalLocs}] -1692
	/Varset LocY[${TotalLocs}] 766
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "7.1"
	/Varset LocX[${TotalLocs}] -1798
	/Varset LocY[${TotalLocs}] 767
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "8"
	/Varset LocX[${TotalLocs}] -1575
	/Varset LocY[${TotalLocs}] 568
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "9"
	/Varset LocX[${TotalLocs}] -1803
	/Varset LocY[${TotalLocs}] 276
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "9.1"
	/Varset LocX[${TotalLocs}] -1912
	/Varset LocY[${TotalLocs}] 226
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130

	/Varcalc TotalLocs ${TotalLocs} +1
	/Varset LocDesc[${TotalLocs}] "1"
	/Varset LocX[${TotalLocs}] -2292
	/Varset LocY[${TotalLocs}] 286
	/Varset LocFace[${TotalLocs}] 60
	/Varset LocDur[${TotalLocs}] 30
	/Varset LocRange[${TotalLocs}] 130
/return
