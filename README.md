Vytvorte jednoduchý interpreter príkazov v jazyku C, ktorý bude prechádzanie súborovým systémom prezentovať formou putovania hráča virtuálnym svetom. Jednotlivé adresáre predstavujú miestnosti, do ktorých sa dá vstúpiť a obsahujú predmety, reprezentované súbormi. Ako dvere na prechod medzi miestnosťami slúžia symbolické linky[2], ktoré odkazujú na iné adresáre. Predmety (súbory ktorých veľkosť v bytoch vyjadruje hmotnosť v gramoch) sa dajú ukladať do vaku (s obmedzenou nosnosťou) a neskôr odkladať v iných miestnostiach. Príkazy, ktoré váš interpreter príkazov nepozná, spracuje pomocou zavolania interpretera príkazov bash. Zoznam príkazov:


 - chod <nazov_miestnosti> - vojde do danej miestnosti 
 - zober <predmet> - zoberie predmet z danej miestnosti
 - poloz <predmet> - uloží predmet z vaku do aktuálnej miestnosti
 - obsahvaku - vypíše obsah vaku
 - hmotnostvaku - vypíše súčet hmotnosti (veľkosti v bytoch) predmetov vo vaku
 - prezri - zobrazí zoznam predmetov v aktuálnej miestnosti
 - cesty - vypíše zoznam miestností, kam môžeme z aktuálnej miestnosti ísť
 - klonuj <predmet> - vytvorí kópiu predmetu v danej miestnosti do vaku
 - zahod <predmet> - zahodí (odstráni) predmet z vaku
 - znic <predmet>- zničí (odstráni) predmet v danej miestnosti
 - preskumaj <predmet> - popise daný predmet
 - koniec - ukončí činnosť interpretra príkazov
 - Pre prezentáciu práce vytvorte svoj vlastný virtuálny svet pozostávajúci z aspoň piatich virtuálnych miestností a niekoľko predmetov.

Copyright © 2000 Your Name <your@address>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
