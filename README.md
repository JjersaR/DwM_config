# Pasos para ejecutar la configuración
## 1.
Clonar repositorio.
## 2.
Ejecutar:
``` sh
sudo make clean install
```
Cada que modifiques la configuración elimina el archivo `config.h`.
## 3.
Cosas que puedo hacer:
``` c
# alt
{ Mod1Mask,      XK_d,      spawn,          SHCMD("rofi -show drun") }, /* rofi */
# super
{ MODKEY,    XK_Return,   spawn,          {.v = termcmd } }, /* kitty */
{ MODKEY,    XK_q,      killclient,     {0} }, /* kill window */
{ MODKEY|ShiftMask,     XK_j,      movestack,      {.i = +1 } }, /* mover ventana */
{ MODKEY|ShiftMask,     XK_k,      movestack,      {.i = -1 } }, /* mover ventana */
{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} } /* reiniciar dwm */
```
