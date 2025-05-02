Cerinte:
1.	Separarea codului în fișiere header (.h sau .hpp) și surse (.cpp):
	•	Clasele mici și legate între ele se pot afla în aceeași pereche de fișiere header-sursă.
	•	Fără using namespace std.
	2.	Moșteniri:
	•	Minim o clasă de bază și 3 clase derivate din aceeași ierarhie.
	•	Ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită.
	3.	Funcții virtuale (pure):
	•	Minim o funcție virtuală specifică temei (nu funcții simple de citire/afișare sau preluate din biblioteci, cum ar fi draw, update, render).
	•	Funcțiile virtuale vor fi apelate prin pointeri la clasa de bază.
	•	Pointerii la clasa de bază vor fi atribute ale altei clase, nu doar pointeri/referințe în main.
	4.	Constructori virtuali (clone):
	•	Constructorii virtuali sunt necesari, dar nu se consideră funcții specifice temei.
	5.	Apelarea constructorului din clasa de bază din constructorii din derivate.
	6.	Clasă cu atribut de tip pointer la o clasă de bază cu derivate:
	•	Apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază.
	7.	Suprascrierea operatorilor de copiere/atribuire (copy/assignment):
	•	Implementați corect operațiile de copiere și atribuire utilizând copy and swap.
	8.	Downcasting:
	•	Utilizați dynamic_cast sau std::dynamic_pointer_cast pentru downcast cu sens.
	9.	Smart pointers:
	•	Este recomandat să folosiți smart pointers (de exemplu, std::unique_ptr, std::shared_ptr).
	10.	Excepții:
	•	O ierarhie proprie de excepții derivată din std::exception.
	•	Minim 3 clase pentru erori specifice distincte.
	•	Clasele de excepții trebuie să trateze categorii de erori distincte (exemplu: citire fișiere cu diverse extensii).
	•	Utilizare corectă a excepțiilor:
	•	throw în constructori.
	•	try/catch în main.
	11.	Funcții și atribute statice:
	•	Definiți funcții și atribute statice acolo unde este cazul.
	12.	STL (Standard Template Library):
	•	Utilizați cât mai mult posibil STL pentru colecții de date și funcții utile.
	13.	Cât mai multe const:
	•	Preferabil să folosiți const acolo unde este posibil pentru a proteja variabilele de modificare.
	14.	Funcții de nivel înalt:
	•	Evitați getters/setters și funcții de low-level. Folosiți funcții de nivel înalt care rezolvă problemele direct.
CLASE:
	1.	Joc:
	•	Clasa principală care reprezintă jocul. Contine logica de generare a codului secret și gestionarea regulilor de feedback în funcție de nivelul de dificultate.
	•	Funcționalități:
	•	Generează un cod secret de 4 cifre.
	•	Permite utilizatorului să facă încercări pentru a ghici codul secret.
	•	După fiecare încercare, se oferă feedback în funcție de numărul de cifre corecte și poziția acestora.
	•	Joacă o rundă sau termină jocul atunci când numărul maxim de încercări este atins.
	2.	RegulaFeedback:
	•	O clasă de tip abstract, care definește comportamentul general al feedback-ului pentru fiecare nivel de dificultate.
	•	Funcționalități:
	•	feedback(): Oferă feedback pentru încercarea făcută pe baza codului secret și a încercării jucătorului.
	•	clone(): Permite clonarea unui obiect al unei clase derivate.
	3.	Usor (Derivată din RegulaFeedback):
	•	Regula de feedback pentru nivelul ușor, care oferă feedback despre numărul de cifre corecte și poziția lor corectă.
	•	Funcționalități:
	•	Implementarea feedback-ului bazat pe corectitudinea și poziția cifrelor.
	•	clone(): Clonarea unui obiect de tip RegulaUsor.
	4.	Mediu (Derivată din RegulaFeedback):
	•	Regula de feedback pentru nivelul mediu, care oferă feedback doar despre numărul de cifre corecte pe poziții corecte.
	•	Funcționalități:
	•	Implementarea feedback-ului pe baza corectitudinii poziției cifrelor.
	•	clone(): Clonarea unui obiect de tip RegulaMediu.
	5.	Greu (Derivată din RegulaFeedback):
	•	Regula de feedback pentru nivelul greu, care nu oferă un feedback detaliat despre corectitudinea pozițiilor, ci doar un mesaj că feedback-ul este indisponibil la acest nivel.
	•	Funcționalități:
	•	clone(): Clonarea unui obiect de tip RegulaGreu.
	6.	Jucator:
	•	Reprezintă un jucător care participă la joc, incluzând numele și scorul.
	•	Funcționalități:
	•	Permite crearea unui jucător cu un scor și un nume specificate.
	•	Suportă calcularea scorului final pe baza numărului de încercări.

Funcționalitatea jocului:
	•	Jocul începe prin alegerea unui nivel de dificultate: ușor, mediu sau greu. Aceste nivele sunt implementate prin clasele Usor, Mediu și Greu.
	•	Jucătorul încearcă să ghicească codul secret, oferindu-i feedback după fiecare încercare.
	•	Nivelul ușor: Oferă feedback detaliat despre cifrele corecte și pozițiile corecte/greșite.
	•	Nivelul mediu: Oferă feedback doar despre cifrele corecte și pozițiile corecte.
	•	Nivelul greu: Nu oferă feedback detaliat, doar un mesaj că feedback-ul este indisponibil.
	•	Scorul: După ce jucătorul ghicește codul, jocul atribuie un scor între 1 și 10 în funcție de câte încercări a folosit pentru a ghici corect codul secret. De exemplu, dacă ghicește din prima, scorul va fi 10, iar dacă folosește mai multe încercări, scorul va scădea.

Fluxul jocului:
	1.	Jocul începe cu alegerea unui nivel de dificultate.
	2.	Jucătorul face încercări de a ghici codul.
	3.	După fiecare încercare, jocul oferă feedback bazat pe nivelul de dificultate ales.
	4.	Dacă jucătorul ghicește codul sau depășește numărul maxim de încercări, jocul se încheie și i se afișează scorul.
