RO:
Proiectul OOP - Dealer de Mașini
Descriere
Acest proiect reprezintă un dealer de mașini, implementat folosind programarea orientată pe obiecte (OOP) în C++.
Proiectul demonstrează abilități avansate de programare, incluzând utilizarea claselor abstracte, suprascrierea operatorilor, gestionarea fișierelor 
și tehnici de data mining pentru analiza activităților utilizatorilor.

Funcționalități
Clase de Bază și Derivate

Client: Clasa de bază pentru gestionarea clienților.

PersoanaJuridica: Clasă derivată din Client, reprezentând clienți persoane juridice.

Dealer: Clasă pentru gestionarea dealer-ului de mașini.

Masina: Clasă pentru reprezentarea mașinilor din stoc.

Incasare: Clasă derivată din AbsIncasare, pentru gestionarea încasărilor.

Interfețe și Clase Abstracte

IClient: Interfață pentru implementarea unor metode specifice clienților.
AbsIncasare: Clasă abstractă pentru definirea metodelor de calcul și afișare a prețurilor.
Funcționalități Avansate

Suprascrierea operatorilor (<<, >>, =, +, -).
Gestionarea memoriei dinamice și a resurselor (copiere profundă, destructori, etc).
Metode de citire și scriere binară în fișiere (ofstream, ifstream).
Data Mining

Clasa DataMining pentru analiza și raportarea activităților utilizatorilor, cum ar fi numărul de afișări și obiectele create.

Clase Principale
Client
Atribute: nume, prenume, nrtel, masinaAchizitionata, metodaPlata, nrRateRamase, rateRamase, suma.
Metode: constructori, destructori, metode de acces și modificare, suprascrierea operatorilor.

PersoanaJuridica (Derivă din Client)
Atribute: codCUI, numefirma.
Metode: constructori, destructori, metode de acces și modificare, suprascrierea operatorilor.

Dealer
Atribute: nume, adresa, nrtel, nrMasiniStoc, masiniStoc.
Metode: constructori, destructori, metode de citire și scriere binară, metode de gestionare a stocului.

Incasare (Derivă din AbsIncasare)
Atribute: luna, an, valoareFaraTva, nrClienti, clienti.
Metode: calcul preț cu TVA, scriere și citire binară, metode de raportare.

Fabrica
Atribute: nume, cifraAfaceri, masina.
Metode: constructori, destructori, metode de acces și modificare, suprascrierea operatorilor.

DataMining
Atribute: nrAfisari, nrObiecte.
Metode: creștere număr de afișări și obiecte, generare rapoarte.

Avantaje și Calități
Modularitate: Proiectul este organizat în clase distincte, fiecare având responsabilități clare.
Extensibilitate: Structura OOP permite adăugarea ușoară de noi funcționalități și clase.
Gestionarea Memoriei: Utilizarea corectă a destructorilor și a copierei profunde asigură gestionarea eficientă a memoriei.
Persistența Datelor: Implementarea metodelor de citire și scriere binară permite stocarea și recuperarea eficientă a datelor.
Analiză Avansată: Funcționalitățile de data mining oferă perspective valoroase asupra utilizării aplicației.

EN:
Car Dealer Project - OOP in C++
Description
This project represents a car dealer implemented using object-oriented programming (OOP) in C++.
The project demonstrates advanced programming skills, including the use of abstract classes, operator overloading, file handling, and data mining techniques for analyzing user activities.

Features
Base and Derived Classes
Client: Base class for managing clients.

PersoanaJuridica: Class derived from Client, representing legal entity clients.

Dealer: Class for managing the car dealer.

Masina: Class for representing cars in stock.

Incasare: Class derived from AbsIncasare, for managing transactions.

Interfaces and Abstract Classes
IClient: Interface for implementing client-specific methods.
AbsIncasare: Abstract class for defining price calculation and display methods.
Advanced Features

Operator overloading (<<, >>, =, +, -).
Dynamic memory and resource management (deep copy, destructors, etc).
Binary file read and write methods (ofstream, ifstream).
Data Mining
DataMining: Class for analyzing and reporting user activities, such as the number of views and objects created.

Main Classes
Client
Attributes: nume, prenume, nrtel, masinaAchizitionata, metodaPlata, nrRateRamase, rateRamase, suma.
Methods: Constructors, destructors, accessor and mutator methods, operator overloading.

PersoanaJuridica (Derived from Client)
Attributes: codCUI, numefirma.
Methods: Constructors, destructors, accessor and mutator methods, operator overloading.

Dealer
Attributes: nume, adresa, nrtel, nrMasiniStoc, masiniStoc.
Methods: Constructors, destructors, binary read and write methods, stock management methods.

Incasare (Derived from AbsIncasare)
Attributes: luna, an, valoareFaraTva, nrClienti, clienti.
Methods: Price calculation with VAT, binary read and write, reporting methods.

Fabrica
Attributes: nume, cifraAfaceri, masina.
Methods: Constructors, destructors, accessor and mutator methods, operator overloading.

DataMining
Attributes: nrAfisari, nrObiecte.
Methods: Increment view and object count, generate reports.

Advantages and Qualities
Modularity: The project is organized into distinct classes, each with clear responsibilities.
Extensibility: The OOP structure allows for easy addition of new features and classes.
Memory Management: Proper use of destructors and deep copy ensures efficient memory management.
Data Persistence: Implementation of binary read and write methods allows for efficient data storage and retrieval.
Advanced Analysis: Data mining functionalities provide valuable insights into application usage.
