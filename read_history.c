#include "shell.h"

extern t_simul	g_shell;

/*------------- proto ---------------*/

/* ================================= */

// fseek (deplace la tete de lecture) {mieux}
// fsetpos (deplace la tete de lecture)
// ftell (donne le position de la tete de lecture)


// to do:
// le deplacement avec les fleches change le texte par ce qu'il y a dans l'historique
// changement de la sortie standart (on vient changer ce qu'il y a apres le prompt)
// lecture a l'envers du fichier .history
// retenir la position du binaire dans la variable globale (pour les verifications de fichiers)

// "https://stackoverflow.com/questions/47503734/what-does-printf-033c-mean"
// "https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h2-Controls-beginning-with-ESC"
// "https://en.wikipedia.org/wiki/ANSI_escape_code"
// "https://en.wikipedia.org/wiki/Ecma_International"
// man console_codes
