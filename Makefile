# Makefile generated by imake - do not edit!
# $XConsortium: imake.c,v 1.51 89/12/12 12:37:30 jim Exp $
#
# The cpp used on this machine replaces all newlines and multiple tabs and
# spaces in a macro expansion with a single space.  Imake tries to compensate
# for this, but is not always successful.
#

###########################################################################
# Makefile generated from "Imake.tmpl" and </tmp/IIf.a0006z>
# $XConsortium: Imake.tmpl,v 1.77 89/12/18 17:01:37 jim Exp $
#
# Platform-specific parameters may be set in the appropriate .cf
# configuration files.  Site-wide parameters may be set in the file
# site.def.  Full rebuilds are recommended if any parameters are changed.
#
# If your C preprocessor doesn't define any unique symbols, you'll need
# to set BOOTSTRAPCFLAGS when rebuilding imake (usually when doing
# "make Makefile", "make Makefiles", or "make World").
#
# If you absolutely can't get imake to work, you'll need to set the
# variables at the top of each Makefile as well as the dependencies at the
# bottom (makedepend will do this automatically).
#

###########################################################################
# platform-specific configuration parameters - edit sun.cf to change

# platform:  Sun OpenWindows 3.0.1
# operating system:  SunOS 5.0

###########################################################################
# site-specific configuration parameters - edit site.def to change

            SHELL = /bin/sh

              TOP = $(OPENWINHOME)
      CURRENT_DIR = .

               AR = ar cq
  BOOTSTRAPCFLAGS =
               CC = gcc

         COMPRESS = compress
              CPP = /lib/cpp $(STD_CPP_DEFINES)
    PREPROCESSCMD = cc -E $(STD_CPP_DEFINES)
          INSTALL = /usr/ucb/install
               LD = ld
             LINT = lint
      LINTLIBFLAG = -o
         LINTOPTS = -ax
               LN = ln -s
             MAKE = make
               MV = mv
               CP = cp

               RM = rm -f
     STD_INCLUDES =
  STD_CPP_DEFINES = -DSYSV
      STD_DEFINES = -DSYSV
 EXTRA_LOAD_FLAGS = -L/usr/openwin/lib -Wl,-R/usr/openwin/lib
  EXTRA_LIBRARIES =
             TAGS = ctags

           MFLAGS = -$(MAKEFLAGS)

    SHAREDCODEDEF = -DSHAREDCODE
         SHLIBDEF = -DSUNSHLIB

    PROTO_DEFINES =

     INSTPGMFLAGS =

     INSTBINFLAGS = -m 0755
     INSTUIDFLAGS = -m 4755
     INSTLIBFLAGS = -m 0664
     INSTINCFLAGS = -m 0444
     INSTMANFLAGS = -m 0444
     INSTDATFLAGS = -m 0444
    INSTKMEMFLAGS = -m 4755

          DESTDIR =

     TOP_INCLUDES = -I$(INCROOT)

      CDEBUGFLAGS = -O2
        CCOPTIONS =
      COMPATFLAGS =

      ALLINCLUDES = $(STD_INCLUDES) $(TOP_INCLUDES) $(INCLUDES) $(EXTRA_INCLUDES)
       ALLDEFINES = $(ALLINCLUDES) $(STD_DEFINES) $(PROTO_DEFINES) $(DEFINES) $(COMPATFLAGS)
           CFLAGS = $(CDEBUGFLAGS) $(CCOPTIONS) $(ALLDEFINES)
        LINTFLAGS = $(LINTOPTS) -DLINT $(ALLDEFINES)
           LDLIBS = $(SYS_LIBRARIES) $(EXTRA_LIBRARIES)
        LDOPTIONS = $(CDEBUGFLAGS) $(CCOPTIONS)
   LDCOMBINEFLAGS = -X -r

        MACROFILE = sun.cf
           RM_CMD = $(RM) *.CKP *.ln *.BAK *.bak *.o core errs ,* *~ *.a .emacs_* tags TAGS make.log MakeOut

    IMAKE_DEFINES =

         IRULESRC = $(CONFIGDIR)
        IMAKE_CMD = $(IMAKE) -DUseInstalled=1  -I$(IRULESRC) $(IMAKE_DEFINES)

     ICONFIGFILES = $(IRULESRC)/Imake.tmpl $(IRULESRC)/Imake.rules \
			$(IRULESRC)/Project.tmpl $(IRULESRC)/site.def \
			$(IRULESRC)/$(MACROFILE) $(EXTRA_ICONFIGFILES)

###########################################################################
# X Window System Build Parameters
# $XConsortium: Project.tmpl,v 1.63 89/12/18 16:46:44 jim Exp $

###########################################################################
# X Window System make variables; this need to be coordinated with rules
# $XConsortium: Project.tmpl,v 1.63 89/12/18 16:46:44 jim Exp $

          PATHSEP = /
        USRLIBDIR = $(DESTDIR)/usr/lib
           BINDIR = $(DESTDIR)/$(OPENWINHOME)/bin
          INCROOT = $(DESTDIR)/$(OPENWINHOME)/include
     BUILDINCROOT = $(TOP)
      BUILDINCDIR = $(BUILDINCROOT)/X11
      BUILDINCTOP = ..
           INCDIR = $(INCROOT)/X11
           ADMDIR = $(DESTDIR)/usr/adm
           LIBDIR = $(DESTDIR)/$(OPENWINHOME)/lib
        CONFIGDIR = $(LIBDIR)/config
       LINTLIBDIR = $(USRLIBDIR)/lint

          FONTDIR = $(LIBDIR)/fonts
         XINITDIR = $(LIBDIR)/xinit
           XDMDIR = $(LIBDIR)/xdm
           AWMDIR = $(LIBDIR)/awm
           TWMDIR = $(LIBDIR)/twm
           GWMDIR = $(LIBDIR)/gwm
          MANPATH = $(DESTDIR)/usr/man
    MANSOURCEPATH = $(MANPATH)/man
           MANDIR = $(MANSOURCEPATH)n
        LIBMANDIR = $(MANSOURCEPATH)3
      XAPPLOADDIR = $(LIBDIR)/app-defaults

        SOXLIBREV = 4.2
          SOXTREV = 4.0
         SOXAWREV = 4.0
        SOOLDXREV = 4.0
         SOXMUREV = 4.0
        SOXEXTREV = 4.0

       FONTCFLAGS = -t

     INSTAPPFLAGS = $(INSTDATFLAGS)

            IMAKE = imake
           DEPEND = makedepend
              RGB = rgb
            FONTC = bdftosnf
        MKFONTDIR = mkfontdir
        MKDIRHIER = /bin/sh $(BINDIR)/mkdirhier.sh

        CONFIGSRC = $(TOP)/config
        CLIENTSRC = $(TOP)/clients
          DEMOSRC = $(TOP)/demos
           LIBSRC = $(TOP)/lib
          FONTSRC = $(TOP)/fonts
       INCLUDESRC = $(TOP)/X11
        SERVERSRC = $(TOP)/server
          UTILSRC = $(TOP)/util
        SCRIPTSRC = $(UTILSRC)/scripts
       EXAMPLESRC = $(TOP)/examples
       CONTRIBSRC = $(TOP)/../contrib
           DOCSRC = $(TOP)/doc
           RGBSRC = $(TOP)/rgb
        DEPENDSRC = $(UTILSRC)/makedepend
         IMAKESRC = $(CONFIGSRC)
         XAUTHSRC = $(LIBSRC)/Xau
          XLIBSRC = $(LIBSRC)/X
           XMUSRC = $(LIBSRC)/Xmu
       TOOLKITSRC = $(LIBSRC)/Xt
       AWIDGETSRC = $(LIBSRC)/Xaw
       OLDXLIBSRC = $(LIBSRC)/oldX
      XDMCPLIBSRC = $(LIBSRC)/Xdmcp
      BDFTOSNFSRC = $(FONTSRC)/bdftosnf
     MKFONTDIRSRC = $(FONTSRC)/mkfontdir
     EXTENSIONSRC = $(TOP)/extensions

  DEPEXTENSIONLIB =
     EXTENSIONLIB = -lXext

          DEPXLIB = $(DEPEXTENSIONLIB)
             XLIB = $(EXTENSIONLIB) -lX11

      DEPXAUTHLIB = $(USRLIBDIR)/libXau.a
         XAUTHLIB =  -lXau

        DEPXMULIB =
           XMULIB = -lXmu

       DEPOLDXLIB =
          OLDXLIB = -loldX

      DEPXTOOLLIB =
         XTOOLLIB = -lXt

        DEPXAWLIB =
           XAWLIB = -lXaw

 LINTEXTENSIONLIB = $(USRLIBDIR)/llib-lXext.ln
         LINTXLIB = $(USRLIBDIR)/llib-lX11.ln
          LINTXMU = $(USRLIBDIR)/llib-lXmu.ln
        LINTXTOOL = $(USRLIBDIR)/llib-lXt.ln
          LINTXAW = $(USRLIBDIR)/llib-lXaw.ln

          DEPLIBS = $(DEPXAWLIB) $(DEPXMULIB) $(DEPXTOOLLIB) $(DEPXLIB)

         DEPLIBS1 = $(DEPLIBS)
         DEPLIBS2 = $(DEPLIBS)
         DEPLIBS3 = $(DEPLIBS)

###########################################################################
# Imake rules for building libraries, programs, scripts, and data files
# rules:  OpenWindows Version 3.0.1, based on X11R4 rules

###########################################################################
# start of Imakefile

#XCOMM $XConsortium: Imakefile,v 1.33 91/07/17 00:48:06 gildea Exp $
#XCOMM
#XCOMM Here is an Imakefile for vtwm.  It depends on having TWMDIR defined
#XCOMM in Imake.tmpl.  I like to use Imakefiles for everything, and I am sure
#XCOMM other people do also, so perhaps you could do us all a favor and
#XCOMM distribute this one.
#XCOMM

         YFLAGS = -d
        DEPLIBS = $(DEPXMULIB) $(DEPEXTENSIONLIB) $(DEPXLIB)
#LOCAL_LIBRARIES = $(XMULIB) $(EXTENSIONLIB) $(XLIB)
 LOCAL_LIBRARIES = -lX11 -lXext -lXmu -lXt -lm

       LINTLIBS = $(LINTXMU) $(LINTEXTENSIONLIB) $(LINTXLIB)
        DEFINES = $(SIGNAL_DEFINES)

           SRCS = gram.c lex.c deftwmrc.c add_window.c gc.c list.c twm.c \
		parse.c menus.c events.c resize.c util.c version.c iconmgr.c \
		cursor.c icons.c desktop.c doors.c

           OBJS = gram.o lex.o deftwmrc.o add_window.o gc.o list.o twm.o \
		parse.o menus.o events.o resize.o util.o version.o iconmgr.o \
		cursor.o icons.o desktop.o doors.o

all:: vtwm

parse.o: parse.c
	$(RM) $@
	$(CC) -c $(CFLAGS) '-DSYSTEM_INIT_FILE="'$(TWMDIR)'/system.vtwmrc"' $*.c

depend:: lex.c gram.c deftwmrc.c

 PROGRAM = vtwm

all:: vtwm

vtwm: $(OBJS) $(DEPLIBS)
	$(RM) $@
	$(CC) -o $@ $(OBJS) $(LDOPTIONS) $(LOCAL_LIBRARIES) $(LDLIBS) $(EXTRA_LOAD_FLAGS)

saber_vtwm:
	#load $(ALLDEFINES) $(SRCS) $(LOCAL_LIBRARIES) $(SYS_LIBRARIES) $(EXTRA_LIBRARIES)

osaber_vtwm:
	#load $(ALLDEFINES) $(OBJS) $(LOCAL_LIBRARIES) $(SYS_LIBRARIES) $(EXTRA_LIBRARIES)

install:: vtwm
	$(INSTALL) -c $(INSTPGMFLAGS)   vtwm $(BINDIR)

install.man:: vtwm.man
	$(INSTALL) -c $(INSTMANFLAGS) vtwm.man $(MANDIR)/vtwm.n

depend::
	$(DEPEND) -s "# DO NOT DELETE" -- $(ALLDEFINES) -- $(SRCS)

lint:
	$(LINT) $(LINTFLAGS) $(SRCS) $(LINTLIBS)
lint1:
	$(LINT) $(LINTFLAGS) $(FILE) $(LINTLIBS)

clean::
	$(RM) $(PROGRAM)

#InstallNonExecFile(system.vtwmrc,$(TWMDIR))

gram.h gram.c: gram.y
	yacc $(YFLAGS) gram.y
	$(MV) y.tab.c gram.c
	$(MV) y.tab.h gram.h

clean::
	$(RM) y.tab.h y.tab.c lex.yy.c gram.h gram.c lex.c deftwmrc.c

deftwmrc.c:  system.vtwmrc
	$(RM) $@
	echo '/* ' >>$@
	echo ' * This file is generated automatically from the default' >>$@
	echo ' * vtwm bindings file system.vtwmrc by the vtwm Imakefile.' >>$@
	echo ' */' >>$@
	echo '' >>$@
	echo 'char *defTwmrc[] = {' >>$@
	sed -e '/^#/d' -e 's/"/\\"/g' -e 's/^/    "/' -e 's/$$/",/' \
		system.vtwmrc >>$@
	echo '    (char *) 0 };' >>$@

###########################################################################
# common rules for all Makefiles - do not edit

emptyrule::

clean::
	$(RM_CMD) \#*

Makefile::
	-@if [ -f Makefile ]; then \
	echo "	$(RM) Makefile.bak; $(MV) Makefile Makefile.bak"; \
	$(RM) Makefile.bak; $(MV) Makefile Makefile.bak; \
	else exit 0; fi
	$(IMAKE_CMD) -DTOPDIR=$(TOP) -DCURDIR=$(CURRENT_DIR)

tags::
	$(TAGS) -w *.[ch]
	$(TAGS) -xw *.[ch] > TAGS

saber:
	#load $(ALLDEFINES) $(SRCS)

osaber:
	#load $(ALLDEFINES) $(OBJS)

###########################################################################
# empty rules for directories that do not have SUBDIRS - do not edit

install::
	@echo "install in $(CURRENT_DIR) done"

install.man::
	@echo "install.man in $(CURRENT_DIR) done"

Makefiles::

includes::

###########################################################################
# dependencies generated by makedepend

