# PatternMatching
  Programele implementate reusesc sa indeplineasca scopurile principale ale proiectului: identificarea apelurilor de sistem si a succesiunii lor si cautarea de semnaturi binare in fluxul de instructiuni.
  Pentru a surprinde in detaliu fiecare functionalitate, am implementat in doua surse diferite(my_strace.c si matching.c).
  
  Target-ul urmarit in matching.c este acela de a genera in consola un raport cu fisierele executabile infectate si neinfectate, impreuna cu numarul acestora. Ideea de rezolvare in acest caz este urmatoarea:
  -am creat o baza de date de semnaturi binare, cautand in fluxul de instructiuni si o baza de date cu executabile, ce urmeaza a fi inspectate
  -am creat doua fisiere(semns si execs) in care am pus denumirile semnaturilor binare si a executabilelor pentru a fi usor parcurse 
  -dupa comparatii succesive, se genereaza raportul despre care am spus mai sus.
  
    
