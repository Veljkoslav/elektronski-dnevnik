Elektronski dnevnik
Projekat iz programiranja – 15. jun 2022.
Veljko Dragićević II7

Svrha napisanog programa jeste posedovanje funkcionalnog elektronskog dnevnika u kojem profesori mogu beležiti postignuća učenika odeljenja u kojem predaju gradivo. U trenutnoj verziji programa, moguće je biti profesor samo u jednom odeljenju, shodno tome i voditi evidenciju samo za jedno odeljenje.

Program nudi tri glavne funkcije iz početnog menija (slika 1), a one su redom: „Registracija novog profesora“, „Prijava postojećim podacima“, „Prijavu na roditeljski nalog“, ali i opciju „Kraj rada“ kojom se program prekida. Pri izboru neke od opcija u bilo kojem meniju, potrebno je uneti broj ispred opisane opcije i pritisnuti taster Enter, odnosno Return na Mac sistemima.
														slika 1: početni meni i tri glavne funkcije

Opcijom, „Registracija novog profesora“ (slika 2), sistem poziva funkciju za registraciju i, ukoliko do tada nije postojala, kreira bazu podataka pod nazivom „profesori.txt“ u kojoj će čuvati upisane podatke nakon procesa registracije. Sistem će nakon toga upitati korisnika za njegovo korisničko ime i lozinku koju će kasnije koristiti pri svakoj sledećoj prijavi, ali i ime, prezime i oznaku odeljenja. Nakon toga, sistem će korisniku potvrditi registraciju i kreirati bazu podataka namenjenu za to odeljenje, te se korisnik može prijaviti u sistem. Napomena: sistem trenutno nema implementiran proces provere podataka koja bi signalizirala ukoliko u bazi već postoji korisnik pod unetim korisničkim imenom, odnosno odeljenje pod istom oznakom.

slika 2: proces registracije novog korisnika 		slika 3: proces prijave postojećeg korisnika


Pri izboru druge opcije, „Prijava postojećim podacima“ (slika 3), korisnik će biti upitan za unos istih podataka koje je koristio pri registraciji. Ukoliko korisnik unese tačne podatke, biće uspešno ulogovan u sistem i odeljenje koje je registrovao. Ukoliko korisnik unese pogrešno korisničko ime ili lozinku, sistem korisniku neće eksplicitno naznačiti koji parametar je pogrešan, ali će ga obavestiti i vratiti u glavni meni (slika 4).


slika 4: primer unosa pogrešnih parametara za prijavu

Uspešnom prijavom i daljim radom programa, profesoru je na raspolaganju novi panel (slika 5) preko kojeg može manipulisati odeljenjem korišćenjem sledećih opcija: „Upisivanje učenika u odeljenje“, „Ispis svih učenika odeljenja“, „Upisivanje ocena učeniku“, „Upisivanje ocena sa kontrolnog zadatka“, „Pregled učenika“ i „Izbor nasumičnog učenika“. Tu su i opcije za promenu korisničkog imena i lozinke, ali i odjavu profesora. 

								slika 5: glavni meni ulogovanog profesora

Izborom prve opcije, „Upisivanje učenika u odeljenje“, (slika 6) sistem će upitati profesora koliko novih učenika želi da upiše u postojeće odeljenje i toliko puta ponoviti registracionu formu u kojoj profesor unosi njihovo ime i prezime, kao i korisničko ime i lozinku koju će kasnije roditelji koristiti kao pristupne podatke u meniju za pristup sistemu. Tada se kreira i baza „roditelji.txt“.

Nakon unošenja svih učenika, sistem će sortirati učenike po njihovom prvom slovu prezimena i moguće je ispisati sve učenika odeljenja korišćenjem druge opcije, „Ispis svih učenika odeljenja“.  (slika 7)

    slika 6: algoritam za upisivanje učenika u odeljenje



slika 7: ispis svih učenika odeljenja

Profesor nekom učeniku može upisivati ocene korišćenjem opcije „Upisivanje ocena učeniku“ (slika 8). Izborom opcije, profesor dobija upit za redni broj učenika, a potom i broj ocena koje želi da upiše učeniku. Nakon upisa ocena, one se čuvaju u bazi odeljenja i tada se mogu prikazati nakon što se roditelj uloguje na svoj roditeljski nalog. Ukoliko profesor unese nepostojeći redni broj učenika, sistem će ga obavestiti o tome. 			slika 8: upis ocena učeniku
Profesor može upisati svim učenicima ocene odjednom koristeći opciju „Upisivanje ocena sa kontrolnog zadatka“, gde je proces isti kao i kod upisivanje pojedinačnih ocena. Napomena: sistem trenutno nema opciju za brisanje već unetih ocena.

Opcijom „Pregled učenika“, profesor može uneti redni broj učenika za kog želi da proveri upisane ocene, pri čemu će program takođe izračunati i prosek ocena i uspeh učenika koji odgovara tom proseku. Analogno tome, opcija „Izbor nasumičnog učenika“ će nasumično odabrati učenika iz odeljenja i prikazati njegove ocene, prosek i uspeh. Ova opcija je pogodna ukoliko profesor želi nasumično da odabere učenika za odgovaranje.

Ukoliko profesor u nekom trenutku proceni da njegovom nalogu nedozvoljeno pristupa neko drugi ili iz bilo kojeg drugog razloga želi da promeni svoje korisničko ime ili lozinku, to može učiniti opcijom „Promena korisničkog imena i lozinke“. Profesor će tada biti dužan da unese trenutno korisničko ime i lozinku, a zatim i nove parametre koje će koristiti pri svakom sledećem ulasku u sistem. Ukoliko profesor unese pogrešno korisničko ime ili lozinku, sistem će ga obavestiti o tome, ali će profesor morati ponovo da pokrene proces.

Nakon završenog rada sa odeljenjem, profesor se može odjaviti korišćenjem istoimene opcije, „Odjava“.

Prijava na roditeljski nalog
Prilikom prethodno objašnjenog procesa upisivanja učenika u odeljenje, profesori su kreirali korisnička imena i lozinke kojim se može pristupiti njihovim nalozima u meniju za pristup sistemu. 

Ukoliko roditelj unese pogrešno korisničko ime ili lozinku, biće obavešten o greški, ali ne i o tome koji parametar je pogrešno unet i biće preusmeren na početak.

Ukoliko roditelj unese tačne parametre, na ekranu će mu biti prikazane ocene njegovog učenika, automatski izračunat prosek ocena i uspeh koji odgovara tom proseku.

Slično kao profesori, roditelji takođe u bilo kojem trenutku mogu promeniti svoju lozinku, ali ne i korisničko ime. Unosom opcije 1, roditelj će biti upitan za trenutnu i novu lozinku. Ukoliko roditelj ne unese tačnu trenutnu lozinku, proces će biti otkazan.


