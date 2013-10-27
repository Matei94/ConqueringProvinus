SatellitePositioning
====================

	Pentru a verifica daca un punct se afla in interiorul triunghiului sau nu, am construit
3 determinanti. Daca acestia se afla de aceeasi parte a lui 0, inseamna ca punctul se afla
in triunghi. Daca punctul se afla pe o latura a triunghiului, teorema functioneaza, insa
atunci cand coordonatele punctului si a unuia din varfuri coincid, teorema nu mai e valabila.
Asa ca am facut o verificare explicita pentru a determina daca punctul si unul din varfuri coincid.

	Determinantii sunt urmatorii:
det1 = det( ((xA,yA,1),(xB,yB,1),(xP,yP,1)) ) 
det2 = det( ((xB,yB,1),(xC,yC,1),(xP,yP,1)) ) 
det3 = det( ((xC,yC,1),(xA,yA,1),(xP,yP,1)) ) 

A, B si C sunt varfurile triunghiului si P este punctul de testat.

	Spor la corectat!
