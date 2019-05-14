// estructures de tot el programa

#define MAX_NOM 50
#define MAX_JUG 10
#define MAX_CARTES 108
#define MAX_COLORS 4
#define MAX_ESPECIAL 6
#define PILA_DESCARTES -1
#define PILA_ROBAR -2
#define SENSE_NUMERO -3
#define SENSE_SEGUENT -4

//assigna a cada color un numero
enum Color_t{
	VERMELL = 0,
	GROC = 1,
	VERD = 2,
	BLAU = 3,
	SENSE_COLOR = 4
};

//assigna a cada tipus de carta un número
enum Especial_t{
	NORMAL = 0,
	SALTAR_TORN = 1,
	CANVIAR_SENTIT = 2,
	ROBAR_2 = 3,
	COMODI_COLOR = 4,
	ROBAR_4 = 5
};


typedef struct{
	enum Color_t color;
	int numero;
	enum Especial_t tipus;
	int propietari; // owner de la carta
	// int seguent; //next carta del mateix propietari
	struct _Carta_t *next;
} Carta_t;


typedef struct{
	bool huma; // diu si es huma o boot
	char nom[MAX_NOM];
	bool agressiu; // diu si es agressiu o no
	int  n_cartes_def; // cartes inicials a la mà
	/*
	Jugador_t *prev;
	Jugador_t *next;
	*/

} Jugador_t;

/*
typedef struct {

} llista_jugadors:
*/


//Ha de ser una llista de cartes
typedef struct{
	int primera_carta;
	int n_cartes; // numero de cartes a la ma
} Ma_t;

typedef struct{
	int n_jugadors;
	// aqui i a la struct de Jugador_t s'ha de mirar si es fa un a llista
	// on cada jugador apunta al seguent i al anterior.
	Jugador_t Jugadors[MAX_JUG]; // lista jugadrs per ordre
	Ma_t ma[MAX_JUG]; // ma = mano = hand
	Ma_t descartades; // "pila" de cartes descartades
	Ma_t a_robar; // "pila" de cartes a robar
	int contador_torns; //indica el número de torns que porta la partida
	int jugador_actual; // en la posició de la llista
	bool sentit_horari; // si es 0 sentit ascendent
} Partida_t;

typedef struct{
	int quantas_cartas;
} PartidaFinalitzada_t;

typedef struct{
	int n_jugadors;
	Jugador_t jugadors[MAX_JUG];
	int partides_guanyades[MAX_JUG];
	int partides_perdudes[MAX_JUG];
	int partides_jugades;
	// vector o llista de PartidasFinalitzades
} Estadisticas_t;
