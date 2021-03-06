/* See LICENSE file for copyright and license details. */

 
/* appearance */

static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 15;       /* snap pixel */
static const unsigned int gappx     = 15;        /* gap pixel between windows */  
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "firacode medium:size=13", "FontAwesome5Brands:size=12:antialias:true", "FontAwesome5Free:size=12:antialias:true", "FontAwesome5Free:style=Solid:size=12:antialias:true"};
static const char dmenufont[]       = "firacode medium:size=13";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#83a598";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "","", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = { 
/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle }, 
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-l", "15", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *discordcmd[]  = { "discord", NULL};
static const char *bravecmd[] = { "brave", NULL};
static const char *spotifycmd[] = { "spotify", NULL}; 
static const char *pcmanfmcmd[] = { "pcmanfm", NULL};
static const char *firefoxcmd[] = {"firefox", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_o,      spawn,         {.v = dmenucmd} },
	{ MODKEY|ShiftMask,             XK_Return, spawn,         {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_k,      spawn,         {.v = discordcmd} },
	{ MODKEY|ShiftMask,             XK_m,      spawn,         {.v = spotifycmd} },
	{ MODKEY|ShiftMask,             XK_h,      spawn,         {.v = pcmanfmcmd} },
	{ MODKEY|ShiftMask,             XK_g,      spawn,         SHCMD("element-desktop")},
	{ MODKEY|ShiftMask,             XK_e,      spawn,         SHCMD("screengrab")},
	{ MODKEY|ShiftMask,             XK_p,      spawn,         SHCMD("librewolf") },
	{ MODKEY|ShiftMask,             XK_b,      spawn,         SHCMD("firefox") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,         SHCMD("slock") },
	{ MODKEY|ShiftMask,             XK_v,      spawn,         SHCMD("pavucontrol") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,         SHCMD("steam") },
	{ MODKEY|ShiftMask,             XK_u,      spawn,         SHCMD("redshift -O 2700K") },
	{ MODKEY|ShiftMask,             XK_l,      spawn,         SHCMD("redshift -x") },
	{ MODKEY|ShiftMask,             XK_e,      spawn,         SHCMD("cd ~/Media/Pictures/ && scrot -s") },
	{ MODKEY|ShiftMask,             XK_c,      spawn,         SHCMD("mupdf ~/Media/Pictures/pain.png") },
	{ MODKEY,                       XK_c,      spawn,         SHCMD("setxkbmap -layout us -variant colemak") },
  { MODKEY,                       XK_q,      spawn,         SHCMD("setxkbmap -layout us ") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_n,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_e,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_s,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_i,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

