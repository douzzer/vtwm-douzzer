/*****************************************************************************/
/**       Copyright 1988 by Evans & Sutherland Computer Corporation,        **/
/**                          Salt Lake City, Utah                           **/
/**  Portions Copyright 1989 by the Massachusetts Institute of Technology   **/
/**                        Cambridge, Massachusetts                         **/
/**                                                                         **/
/**                           All Rights Reserved                           **/
/**                                                                         **/
/**    Permission to use, copy, modify, and distribute this software and    **/
/**    its documentation  for  any  purpose  and  without  fee is hereby    **/
/**    granted, provided that the above copyright notice appear  in  all    **/
/**    copies and that both  that  copyright  notice  and  this  permis-    **/
/**    sion  notice appear in supporting  documentation,  and  that  the    **/
/**    names of Evans & Sutherland and M.I.T. not be used in advertising    **/
/**    in publicity pertaining to distribution of the  software  without    **/
/**    specific, written prior permission.                                  **/
/**                                                                         **/
/**    EVANS & SUTHERLAND AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD    **/
/**    TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  OF  MERCHANT-    **/
/**    ABILITY  AND  FITNESS,  IN  NO  EVENT SHALL EVANS & SUTHERLAND OR    **/
/**    M.I.T. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAM-    **/
/**    AGES OR  ANY DAMAGES WHATSOEVER  RESULTING FROM LOSS OF USE, DATA    **/
/**    OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER    **/
/**    TORTIOUS ACTION, ARISING OUT OF OR IN  CONNECTION  WITH  THE  USE    **/
/**    OR PERFORMANCE OF THIS SOFTWARE.                                     **/
/*****************************************************************************/

/***********************************************************************
 *
 * $XConsortium: twm.h,v 1.74 91/05/31 17:38:30 dave Exp $
 *
 * twm include file
 *
 * 28-Oct-87 Thomas E. LaStrange	File created
 * 10-Oct-90 David M. Sternlicht        Storeing saved colors on root
 ***********************************************************************/

#ifndef _TWM_
#define _TWM_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/extensions/shape.h>
#ifdef TWM_USE_XFT
#include <X11/Xft/Xft.h>
#endif
#ifdef TWM_USE_XRANDR
#include <X11/extensions/Xrandr.h>
#endif

/*
 * This accomodates systems that simply cannot handle the
 * duplicate typedef declaration of 'Pixel'. On the other hand,
 * if your make halts with complaints of an unknown datatype
 * 'Pixel', add "EXTRA_DEFINES=-DNEED_PIXEL_T" to the make
 * command. Submitted by Nelson H. F. Beebe
 */
#include <X11/Intrinsic.h>
#ifdef NEED_PIXEL_T
typedef unsigned long Pixel;
#endif
#define PIXEL_ALREADY_TYPEDEFED	/* for Xmu/Drawing.h */


#ifndef WithdrawnState
#define WithdrawnState 0
#endif

#ifdef SIGNALRETURNSINT
#define SIGNAL_T int
#define SIGNAL_RETURN return 0
#else
#define SIGNAL_T void
#define SIGNAL_RETURN return
#endif

typedef SIGNAL_T(*SigProc) (int);	/* type of function returned by signal() */

#define BW 2			/* border width */
#define BW2 4			/* border width  * 2 */

#ifndef TRUE
#define TRUE	1
#define FALSE	0
#endif

#define NULLSTR ((char *) NULL)

/* info stings defines */
#define INFO_LINES 30
#define INFO_SIZE 200

/* contexts for button presses */
#define C_NO_CONTEXT	-1
#define C_WINDOW	0
#define C_TITLE		1
#define C_ICON		2
#define C_ROOT		3
#define C_FRAME		4
#define C_ICONMGR	5
#define C_NAME		6
#define C_IDENTIFY      7
#define C_VIRTUAL	8
#define C_VIRTUAL_WIN	9
#define C_DOOR		10
#define NUM_CONTEXTS	11

#define C_WINDOW_BIT	(1 << C_WINDOW)
#define C_TITLE_BIT	(1 << C_TITLE)
#define C_ICON_BIT	(1 << C_ICON)
#define C_ROOT_BIT	(1 << C_ROOT)
#define C_FRAME_BIT	(1 << C_FRAME)
#define C_ICONMGR_BIT	(1 << C_ICONMGR)
#define C_NAME_BIT	(1 << C_NAME)
#define C_VIRTUAL_BIT	(1 << C_VIRTUAL)
#define C_VIRTUAL_WIN_BIT (1 << C_VIRTUAL_WIN)
#define C_DOOR_BIT      (1 << C_DOOR)

#define C_ALL_BITS	(C_WINDOW_BIT | C_TITLE_BIT | C_ICON_BIT |\
			 C_ROOT_BIT | C_FRAME_BIT | C_ICONMGR_BIT |\
			 C_VIRTUAL_BIT | C_VIRTUAL_WIN_BIT | C_DOOR_BIT)

/* modifiers for button presses */

/* added "LockMask" - djhjr - 9/10/03 */
#define MOD_SIZE	((ShiftMask | LockMask | ControlMask | Mod1Mask \
			  | Mod2Mask | Mod3Mask | Mod4Mask | Mod5Mask) + 1)

/* definitions from MwmUtil.h - submitted by Jonathan Paisley - 11/8/02 */
#define MWM_HINTS_FUNCTIONS     (1L << 0)
#define MWM_HINTS_DECORATIONS   (1L << 1)
#define MWM_HINTS_INPUT_MODE    (1L << 2)
#define MWM_HINTS_STATUS        (1L << 3)

#define MWM_FUNC_ALL            (1L << 0)
#define MWM_FUNC_RESIZE         (1L << 1)
#define MWM_FUNC_MOVE           (1L << 2)
#define MWM_FUNC_MINIMIZE       (1L << 3)
#define MWM_FUNC_MAXIMIZE       (1L << 4)
#define MWM_FUNC_CLOSE          (1L << 5)

#define MWM_DECOR_ALL           (1L << 0)
#define MWM_DECOR_BORDER        (1L << 1)
#define MWM_DECOR_RESIZEH       (1L << 2)
#define MWM_DECOR_TITLE         (1L << 3)
#define MWM_DECOR_MENU          (1L << 4)
#define MWM_DECOR_MINIMIZE      (1L << 5)
#define MWM_DECOR_MAXIMIZE      (1L << 6)

#define MWM_INPUT_MODELESS 0
#define MWM_INPUT_PRIMARY_APPLICATION_MODAL 1
#define MWM_INPUT_SYSTEM_MODAL 2
#define MWM_INPUT_FULL_APPLICATION_MODAL 3
#define MWM_INPUT_APPLICATION_MODAL MWM_INPUT_PRIMARY_APPLICATION_MODAL

#define MWM_TEAROFF_WINDOW      (1L<<0)

typedef struct
{
  long flags;
  long functions;
  long decorations;
  long input_mode;
  long state;
} MotifWmHints;

#define TITLE_BAR_SPACE         1	/* 2 pixel space bordering chars */
#define TITLE_BAR_FONT_HEIGHT   15	/* max of 15 pixel high chars */
#define TITLE_BAR_HEIGHT        (TITLE_BAR_FONT_HEIGHT+(2*TITLE_BAR_SPACE))

/* defines for zooming/unzooming */
#define ZOOM_NONE 0

/* Change the foreground and background colors of the NormalGC of the specified
 * screen. */
#define FB(scr, fix_fore, fix_back)\
    Gcv.foreground = fix_fore;\
    Gcv.background = fix_back;\
    XChangeGC(dpy, (scr)->NormalGC, GCForeground|GCBackground, &Gcv)

typedef enum
{ on, off } ButtonState;

typedef struct MyFont
{
  char *name;			/* name of the font */
  XFontStruct *font;		/* font structure */
  XFontSet fontset;
#ifdef TWM_USE_XFT
  XftFont *xft;			/* Xft font structure for Window XID */
#endif
  int height;			/* height of the font */
  int y;			/* Y coordinate to draw characters */
  int ascent;
  int descent;
  int offset_x;
  int offset_y;
} MyFont;

typedef struct MyWindow		/* MyFont/ColorPair text rendering */
{
  Window win;			/* Window XID */
#ifdef TWM_USE_XFT
  XftDraw *xft;			/* Xft draw context for Window XID */
#endif
} MyWindow;

typedef struct ColorPair
{
  Pixel fore, back;
#ifdef TWM_USE_XFT
  XftColor xft;			/* Xft text colour for Window XID */
#endif
  Pixel shadc, shadd;
} ColorPair;

typedef struct _TitleButton
{
  struct _TitleButton *next;	/* next link in chain */
  char *name;			/* bitmap name in case of deferal */
  int srcx, srcy;		/* from where to start copying */
  unsigned int width, height;	/* size of pixmap */
  int dstx, dsty;		/* to where to start copying */
  int func;			/* function to execute */
  char *action;			/* optional action arg */
  char *action2;		/* optional action arg */
  char *action3;		/* optional action arg */
  char *action4;		/* optional action arg */
  struct MenuRoot *menuroot;	/* menu to pop on F_MENU */
  Bool rightside;		/* t: on right, f: on left */
} TitleButton;

typedef struct _TBWindow
{
  Window window;		/* which window in this frame */
  TitleButton *info;		/* description of this window */
} TBWindow;

typedef struct _SqueezeInfo
{
  int justify;			/* left, center, right */
  int num;			/* signed pixel count or numerator */
  int denom;			/* 0 for pix count or denominator */
} SqueezeInfo;

#define J_LEFT			1
#define J_CENTER		2
#define J_RIGHT			3

/* Colormap window entry for each window in WM_COLORMAP_WINDOWS
 * ICCCM property.
 */
typedef struct TwmColormap
{
  Colormap c;			/* Colormap id */
  int state;			/* install(ability) state */
  unsigned long install_req;	/* request number which installed it */
  Window w;			/* window causing load of color table */
  int refcnt;
} TwmColormap;

#define CM_INSTALLABLE		1
#define CM_INSTALLED		2
#define CM_INSTALL		4

typedef struct ColormapWindow
{
  Window w;			/* Window id */
  TwmColormap *colormap;	/* Colormap for this window */
  int visibility;		/* Visibility of this window */
  int refcnt;
} ColormapWindow;

typedef struct Colormaps
{
  ColormapWindow **cwins;	/* current list of colormap windows */
  int number_cwins;		/* number of elements in current list */
  char *scoreboard;		/* conflicts between installable colortables */
} Colormaps;

#define ColormapsScoreboardLength(cm) ((cm)->number_cwins * \
				       ((cm)->number_cwins - 1) / 2)

/* for each window that is on the display, one of these structures
 * is allocated and linked into a list 
 */
typedef struct TwmWindow
{
  struct TwmWindow *next;	/* next twm window */
  struct TwmWindow *prev;	/* previous twm window */
  Window w;			/* the child window */
  MyWindow VirtualDesktopDisplayWindow;	/* the representation of this window in the vd display */
  int old_bw;			/* border width before reparenting */
  Window frame;			/* the frame window */
  MyWindow title_w;		/* the title bar window */
  Window hilite_w;		/* the hilite window */
  Pixmap gray;
  MyWindow icon_w;		/* the icon window */
  Window icon_bm_w;		/* the icon bitmap window */
  int frame_x;			/* x position of frame */
  int frame_y;			/* y position of frame */
  int virtual_frame_x;		/* virtual x position of frame */
  int virtual_frame_y;		/* virtual y position of frame */
  int frame_width;		/* width of frame */
  int frame_height;		/* height of frame */
  int frame_bw;			/* borderwidth of frame */

  int last_ConfigureNotify_frame_x;
  int last_ConfigureNotify_frame_y;
  int last_ConfigureNotify_frame_width;
  int last_ConfigureNotify_frame_height;

  int frame_bw3D;		/* 3D borderwidth of frame */

  int title_x;
  int title_y;
  int virtual_title_x;		/* virtual x position of title */
  int virtual_title_y;		/* virtual y position of title */
  int icon_x;			/* icon text x coordinate */
  int icon_y;			/* icon text y coordiante */
  int virtual_icon_x;		/* virtual x position of icon */
  int virtual_icon_y;		/* virtual y position of icon */
  int icon_w_width;		/* width of the icon window */
  int icon_w_height;		/* height of the icon window */
  int icon_width;		/* width of the icon bitmap */
  int icon_height;		/* height of the icon bitmap */
  int title_height;		/* height of the title bar */
  int title_width;		/* width of the title bar */
  char *full_name;		/* full name of the window */
  char *name;			/* name of the window */
  char *icon_name;		/* name of the icon */
  int name_width;		/* width of name text */
  int highlightx;		/* start of highlight window */
  int rightx;			/* start of right buttons */
  XWindowAttributes attr;	/* the child window attributes */
  XSizeHints hints;		/* normal hints */
  XWMHints *wmhints;		/* WM hints */
  MotifWmHints mwmhints;	/* MWM hints - by Jonathan Paisley - 11/8/02 */
  Window group;			/* group ID */
  XClassHint class;
  struct WList *list;

    /***********************************************************************
     * color definitions per window
     **********************************************************************/
  Pixel icon_border;		/* border color */

  ColorPair border;		/* border color */

  ColorPair border_tile;
  ColorPair title;
  ColorPair iconc;
  ColorPair virtual;

  short mapped;			/* is the window mapped ? */
  short zoomed;			/* is the window zoomed? */
  short highlight;		/* should highlight this window */
  short iconmgr;		/* this is an icon manager window */
  short icon;			/* is the window an icon now ? */

  struct
  {
    unsigned int iconified:1;
    unsigned int icon_on:1;
    unsigned int auto_raise:1;
    unsigned int forced:1;
    unsigned int icon_not_ours:1;
    unsigned int icon_moved:1;
    unsigned int stackmode:1;
    unsigned int iconify_by_unmapping:1;
    unsigned int transient:1;
    unsigned int titlehighlight:1;
    unsigned int wShaped:1;
    unsigned int nailed:1;
    unsigned int immutable:1;
    unsigned int showindesktopdisplay:1;

    /* djhjr - 4/6/98 */
    unsigned int opaque_move:1;
    unsigned int opaque_resize:1;

  } twmflags;
#define iconified					twmflags.iconified
#define icon_on						twmflags.icon_on
#define auto_raise					twmflags.auto_raise
#define forced						twmflags.forced
#define icon_not_ours				twmflags.icon_not_ours
#define icon_moved					twmflags.icon_moved
#define stackmode					twmflags.stackmode
#define iconify_by_unmapping		twmflags.iconify_by_unmapping
#define transient					twmflags.transient
#define titlehighlight				twmflags.titlehighlight
#define wShaped						twmflags.wShaped
#define nailed						twmflags.nailed
#define immutable					twmflags.immutable
#define showindesktopdisplay		twmflags.showindesktopdisplay

/* djhjr - 4/6/98 */
#define opaque_move					twmflags.opaque_move
#define opaque_resize				twmflags.opaque_resize

  Window transientfor;		/* window contained in XA_XM_TRANSIENT_FOR */
  struct IconMgr *iconmgrp;	/* pointer to it if this is an icon manager */
  int save_frame_x;		/* x position of frame in virtual coordinates */
  int save_frame_y;		/* y position of frame in virtual coordinates */
  int save_frame_width;		/* width of frame */
  int save_frame_height;	/* height of frame */
  int save_tile[4];		/* tile geometry in the moment of zoom in virtual coordinates */
  unsigned long protocols;	/* which protocols this window handles */
  Colormaps cmaps;		/* colormaps for this application */
  TBWindow *titlebuttons;
  SqueezeInfo *squeeze_info;	/* should the title be squeezed? */
  struct
  {
    struct TwmWindow *next, *prev;
  } ring;
} TwmWindow;

#define DoesWmTakeFocus		(1L << 0)
#define DoesWmSaveYourself	(1L << 1)
#define DoesWmDeleteWindow	(1L << 2)

#define TBPM_DOT ":dot"		/* name of titlebar pixmap for dot */
#define TBPM_ICONIFY ":iconify"	/* same image as dot */
#define TBPM_RESIZE ":resize"	/* name of titlebar pixmap for resize button */
#define TBPM_XLOGO ":xlogo"	/* name of titlebar pixmap for xlogo */
#define TBPM_DELETE ":delete"	/* same image as xlogo */
#define TBPM_MENU ":menu"	/* name of titlebar pixmap for menus */
#define TBPM_QUESTION ":question"	/* name of unknown titlebar pixmap */

#define TBPM_RARROW ":rarrow"	/* name of right arrow pixmap */
#define TBPM_DARROW ":darrow"	/* name of down arrow pixmap */

#define TBPM_3DDOT ":xpm:dot"	/* name of titlebar pixmap for dot */
#define TBPM_3DRESIZE ":xpm:resize"	/* name of titlebar pixmap for resize button */
#define TBPM_3DMENU ":xpm:menu"	/* name of titlebar pixmap for menus */
#define TBPM_3DZOOM ":xpm:zoom"
#define TBPM_3DBAR ":xpm:bar"

#define TBPM_3DRARROW ":xpm:rarrow"	/* name of right arrow pixmap */
#define TBPM_3DDARROW ":xpm:darrow"	/* name of down arrow pixmap */

#define TBPM_3DRAISEDBOX ":xpm:raisedbox"	/* name of raised box highlight pixmap */
#define TBPM_3DSUNKENBOX ":xpm:sunkenbox"	/* name of sunken box highlight pixmap */
#define TBPM_3DRAISEDLINES ":xpm:raisedlines"	/* name of raised lines highlight pixmap */
#define TBPM_3DSUNKENLINES ":xpm:sunkenlines"	/* name of sunken lines highlight pixmap */

#define TBPM_3DBOX ":xpm:box"	/* name of box pixmap */
#define TBPM_3DLINES ":xpm:lines"	/* name of lines pixmap */

#ifndef X_NOT_STDC_ENV
#include <stdlib.h>
#else
extern char *malloc(), *calloc(), *realloc(), *getenv();
extern void free();
#endif

#if defined(HAVE_RPLAY) || defined(HAVE_ESD) || defined(HAVE_OSS)
#define SOUND_SUPPORT
extern SIGNAL_T PlaySoundDone(int);
extern SIGNAL_T HandleChildExit();
void Done(int);
extern SIGNAL_T QueueRestartVtwm(int);
#else
extern SIGNAL_T Done(int);
extern SIGNAL_T QueueRestartVtwm(int);
#endif


extern char *ProgramName;
extern Display *dpy;
extern Window ResizeWindow;	/* the window we are resizing */
extern int HasShape;		/* this server supports Shape extension */

#ifdef TWM_USE_XRANDR
extern int HasXrandr;		/* this server supports XRANDR extension */
#endif

extern int PreviousScreen;
extern int NumButtons;
extern volatile int IsDone;
extern volatile int ReqWakeup;

extern Cursor UpperLeftCursor;
extern Cursor RightButt;
extern Cursor MiddleButt;
extern Cursor LeftButt;

extern XClassHint NoClass;

extern XContext TwmContext;	/* context key for storing the TwmWindow for
				 * a window */
extern XContext MenuContext;	/* context key for storing the MenuRoot
				 * corresponding to a menu window */
extern XContext IconManagerContext;
extern XContext VirtualContext;
extern XContext ScreenContext;	/* context key for storing the ScreenInfo*
				 * for the screen on which a window appears */
extern XContext ColormapContext;
extern XContext DoorContext;

extern char *Home;
extern int HomeLen;
extern int ParseError;

extern int HandlingEvents;

extern Window JunkRoot;
extern Window JunkChild;
extern int JunkX;
extern int JunkY;
extern unsigned int JunkWidth, JunkHeight, JunkBW, JunkDepth, JunkMask;
extern XGCValues Gcv;		/* Scratch XGCValues. */
extern int InfoLines;
extern char Info[][INFO_SIZE];
extern int Argc;
extern char **Argv;
extern char **Environ;


extern Bool ErrorOccurred;
extern XErrorEvent LastErrorEvent;

#define ResetError() (ErrorOccurred = False)

extern Bool RestartPreviousState;
extern Bool AutoResizeKeepOnScreen;

extern Bool use_fontset;

extern TwmWindow *Focus;
extern short FocusRoot;

extern TwmWindow *CurrentTwmSubjectWindow;

extern Atom _XA_MIT_PRIORITY_COLORS;
extern Atom _XA_WM_CHANGE_STATE;
extern Atom _XA_WM_STATE;
extern Atom _XA_WM_COLORMAP_WINDOWS;
extern Atom _XA_WM_PROTOCOLS;
extern Atom _XA_WM_TAKE_FOCUS;
extern Atom _XA_WM_SAVE_YOURSELF;
extern Atom _XA_WM_DELETE_WINDOW;

extern Atom _XA_TWM_RESTART;

#ifdef TWM_USE_OPACITY
extern Atom _XA_NET_WM_WINDOW_OPACITY;
#endif

#ifdef TWM_USE_SLOPPYFOCUS
extern int SloppyFocus;
#endif
extern int RecoverStolenFocusAttempts;
extern int RecoverStolenFocusTimeout;

#endif /* _TWM_ */


/*
  Local Variables:
  mode:c
  c-file-style:"GNU"
  c-file-offsets:((substatement-open 0)(brace-list-open 0)(c-hanging-comment-ender-p . nil)(c-hanging-comment-beginner-p . nil)(comment-start . "// ")(comment-end . "")(comment-column . 48))
  End:
*/
/* vim: sw=2
*/
