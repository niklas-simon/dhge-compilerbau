
// Turtle-Graphics-Compiler:
// Deklaration und Initialisierung des Arrays für die Namenstabelle
//
// Klaus Kusche 2021, 2022

// für sin, cos, ...
#include <math.h>
// für NULL
#include <stddef.h>

#include "turtle.h"

// Das Array für alle Namen
// ein linear durchsuchtes Array ist performancemäßig eine Katastrophe
// (und limitiert die Anzahl der Namen),
// aber unsere Programme werden kurz sein und nur wenige Namen enthalten...
// Bei einem ernsthaften Compiler müsste das eine Hashtable oder ein Baum sein!
// Vorne im Array stehen alle vordefinierten globalen Variablen,
// vordefinierten Funktionen und Schlüsselwörter
// dahinter werden vom Lexer alle eigenen Namen eingetragen
//
// Da name_tab global ist,
// haben alle unbelegten Einträge automatisch NULL als Namens-Pointer
// Man durchsucht das Array daher bis zum ersten NULL-Eintrag,
// und wenn man den Namen bis dahin nicht gefunden hat,
// kann man ihn in diesem NULL-Eintrag neu speichern

#ifdef GERMAN

nameentry_t name_tab[MAX_NAMES] =
{
  { name_pvar_ro, "@richtung", { .p_val = &g_dir } },
  { name_pvar_ro, "@entfernung", { .p_val = &g_dist } },
  { name_pvar_ro, "@x", { .p_val = &g_x } },
  { name_pvar_ro, "@y", { .p_val = &g_y } },
  { name_pvar_ro, "@1", { .p_val = &(g_args[1]) } },
  { name_pvar_ro, "@2", { .p_val = &(g_args[2]) } },
  { name_pvar_ro, "@3", { .p_val = &(g_args[3]) } },
  { name_pvar_ro, "@4", { .p_val = &(g_args[4]) } },
  { name_pvar_ro, "@5", { .p_val = &(g_args[5]) } },
  { name_pvar_ro, "@6", { .p_val = &(g_args[6]) } },
  { name_pvar_ro, "@7", { .p_val = &(g_args[7]) } },
  { name_pvar_ro, "@8", { .p_val = &(g_args[8]) } },
  { name_pvar_ro, "@9", { .p_val = &(g_args[9]) } },
  { name_pvar_ro, "@pi", { .p_val = &g_pi } },
  { name_pvar_rw, "@max_x", { .p_val = &g_max_x } },
  { name_pvar_rw, "@max_y", { .p_val = &g_max_y } },
  { name_pvar_rw, "@verz", { .p_val = &g_delay } },
  { name_pvar_rw, "@rot", { .p_val = &g_red } },
  { name_pvar_rw, "@gruen", { .p_val = &g_green } },
  { name_pvar_rw, "@blau", { .p_val = &g_blue } },
  { name_math_sin, "sin", { .math = sin } },
  { name_math_cos, "cos", { .math = cos } },
  { name_math_tan, "tan", { .math = tan } },
  { name_math_sqrt, "wurzel", { .math = sqrt } },
  { name_math_rand, "zufall", { .math = NULL } },
  { keyw_walk, "geh", { 0 } },
  { keyw_jump, "spring", { 0 } },
  { keyw_back, "rueckw", { 0 } },
  { keyw_home, "heim", { 0 } },
  { keyw_turn, "dreh", { 0 } },
  { keyw_left, "links", { 0 } },
  { keyw_right, "rechts", { 0 } },
  { keyw_direction, "richtung", { 0 } },
  { keyw_clear, "schwarz", { 0 } },
  { keyw_stop, "stop", { 0 } },
  { keyw_finish, "schluss", { 0 } },
  { keyw_path, "figur", { 0 } },
  { keyw_color, "farbe", { 0 } },
  { keyw_store, "speichere", { 0 } },
  { keyw_in, "in", { 0 } },
  { keyw_add, "add", { 0 } },
  { keyw_addto, "zu", { 0 } },
  { keyw_sub, "sub", { 0 } },
  { keyw_subfrom, "von", { 0 } },  // auch für countfrom
  { keyw_mul, "mul", { 0 } },
  { keyw_mulby, "mit", { 0 } },
  { keyw_div, "div", { 0 } },
  { keyw_divby, "durch", { 0 } },
  { keyw_mark, "marke", { 0 } },
  { keyw_if, "wenn", { 0 } },
  { keyw_then, "dann", { 0 } },
  { keyw_else, "sonst", { 0 } },
  { keyw_endif, "wenn_ende", { 0 } },
  { keyw_do, "mach", { 0 } },
  { keyw_times, "mal", { 0 } },
  { keyw_done, "mach_ende", { 0 } },
  { keyw_counter, "zaehler", { 0 } },
  { keyw_countto, "bis", { 0 } },   // auch für until
  { keyw_downto, "runter_bis", { 0 } },
  { keyw_step, "schritt", { 0 } },
  { keyw_while, "solange", { 0 } },
  { keyw_repeat, "wiederhole", { 0 } },
  { keyw_endpath, "figur_ende", { 0 } },
  { keyw_calculation, "rechnung", { 0 } },
  { keyw_returns, "ergebnis", { 0 } },
  { keyw_endcalc, "rech_ende", { 0 } },
  { keyw_begin, "programm", { 0 } },
  { keyw_end, "prog_ende", { 0 } },
  { keyw_and, "und", { 0 } },
  { keyw_or, "oder", { 0 } },
  { keyw_not, "nicht", { 0 } }
};

#else

nameentry_t name_tab[MAX_NAMES] =
{
  { name_pvar_ro, "@dir", { .p_val = &g_dir } },
  { name_pvar_ro, "@dist", { .p_val = &g_dist } },
  { name_pvar_ro, "@x", { .p_val = &g_x } },
  { name_pvar_ro, "@y", { .p_val = &g_y } },
  { name_pvar_ro, "@1", { .p_val = &(g_args[1]) } },
  { name_pvar_ro, "@2", { .p_val = &(g_args[2]) } },
  { name_pvar_ro, "@3", { .p_val = &(g_args[3]) } },
  { name_pvar_ro, "@4", { .p_val = &(g_args[4]) } },
  { name_pvar_ro, "@5", { .p_val = &(g_args[5]) } },
  { name_pvar_ro, "@6", { .p_val = &(g_args[6]) } },
  { name_pvar_ro, "@7", { .p_val = &(g_args[7]) } },
  { name_pvar_ro, "@8", { .p_val = &(g_args[8]) } },
  { name_pvar_ro, "@9", { .p_val = &(g_args[9]) } },
  { name_pvar_ro, "@pi", { .p_val = &g_pi } },
  { name_pvar_rw, "@max_x", { .p_val = &g_max_x } },
  { name_pvar_rw, "@max_y", { .p_val = &g_max_y } },
  { name_pvar_rw, "@delay", { .p_val = &g_delay } },
  { name_pvar_rw, "@red", { .p_val = &g_red } },
  { name_pvar_rw, "@green", { .p_val = &g_green } },
  { name_pvar_rw, "@blue", { .p_val = &g_blue } },
  { name_math_sin, "sin", { .math = sin } },
  { name_math_cos, "cos", { .math = cos } },
  { name_math_tan, "tan", { .math = tan } },
  { name_math_sqrt, "sqrt", { .math = sqrt } },
  { name_math_rand, "rand", { .math = NULL } },
  { keyw_walk, "walk", { 0 } },
  { keyw_jump, "jump", { 0 } },
  { keyw_back, "back", { 0 } },
  { keyw_home, "home", { 0 } },
  { keyw_turn, "turn", { 0 } },
  { keyw_left, "left", { 0 } },
  { keyw_right, "right", { 0 } },
  { keyw_direction, "direction", { 0 } },
  { keyw_clear, "clear", { 0 } },
  { keyw_stop, "stop", { 0 } },
  { keyw_finish, "finish", { 0 } },
  { keyw_path, "path", { 0 } },
  { keyw_color, "color", { 0 } },
  { keyw_store, "store", { 0 } },
  { keyw_in, "in", { 0 } },
  { keyw_add, "add", { 0 } },
  { keyw_addto, "to", { 0 } },      // auch für countto
  { keyw_sub, "sub", { 0 } },
  { keyw_subfrom, "from", { 0 } },  // auch für countfrom
  { keyw_mul, "mul", { 0 } },
  { keyw_mulby, "by", { 0 } },      // auch für divby
  { keyw_div, "div", { 0 } },
  { keyw_mark, "mark", { 0 } },
  { keyw_if, "if", { 0 } },
  { keyw_then, "then", { 0 } },
  { keyw_else, "else", { 0 } },
  { keyw_endif, "endif", { 0 } },
  { keyw_do, "do", { 0 } },
  { keyw_times, "times", { 0 } },
  { keyw_done, "done", { 0 } },
  { keyw_counter, "counter", { 0 } },
  { keyw_downto, "downto", { 0 } },
  { keyw_step, "step", { 0 } },
  { keyw_while, "while", { 0 } },
  { keyw_repeat, "repeat", { 0 } },
  { keyw_until, "until", { 0 } },
  { keyw_endpath, "endpath", { 0 } },
  { keyw_calculation, "calculation", { 0 } },
  { keyw_returns, "returns", { 0 } },
  { keyw_endcalc, "endcalc", { 0 } },
  { keyw_begin, "begin", { 0 } },
  { keyw_end, "end", { 0 } },
  { keyw_and, "and", { 0 } },
  { keyw_or, "or", { 0 } },
  { keyw_not, "not", { 0 } }
};

#endif
