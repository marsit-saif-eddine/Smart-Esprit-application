## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartesprit

smartesprit_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        header.c header.h\
	file.c file.h\
	filestock.c filestock.h\
	rec.c rec.h\
	nutro.c nutro.h\
	utilisateurs.c utilisateurs.h

smartesprit_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

