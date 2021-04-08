/* user and group to drop privileges to */
static const char *user  = "henry";
static const char *group = "video";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#ffa800",   /* during input */
	[FAILED] = "#999999",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
