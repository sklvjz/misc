#===============================================================================
#
#         File: Makefile
#  Description: 
#
#        Usage: make              (generate executable(s)                    )
#               make clean        (remove objects, executables, prerequisits )
#               make tarball      (generate compressed archive               )
#               make zip          (generate compressed archive               )
#                                  
#       Author: Dr.-Ing. Fritz Mehner
#        Email: mehner@mfh-iserlohn.de
#      Created: 
#
#===============================================================================


CC              = gcc
CCP             = g++
CFLAGS          = -c -g -Wall
LFLAGS          = -g
SYS_LIBS        = -lm -lpthread
TARBALL_EXCLUDE = "*.{o,gz,zip}"
ZIP_EXCLUDE     = *.o *.gz *.zip

TARGETS	= main main2

#---------- targets --------------------------------------
all:	$(TARGETS)

%.o:	%.c
			$(CC) $(CFLAGS) $*.c

%.o:	%.cc
			$(CCP) $(CFLAGS) $*.cc
 
#---------- target 1 -------------------------------------
#  C  target
main:	main.o
					$(CC) $(LFLAGS) -o $@ $@.o  $(SYS_LIBS)

#---------- target 2 -------------------------------------
# C++ target
main2:	main2.o
					$(CCP) $(LFLAGS) -o $@ $@.o  $(SYS_LIBS)


#---------- target 3 -------------------------------------



#---------- tarball --------------------------------------
tarball:
					lokaldir=`pwd`; lokaldir=$${lokaldir##*/}; \
					rm --force $$lokaldir.tar.gz;              \
					tar --exclude=$(TARBALL_EXCLUDE)           \
					    --create                               \
					    --gzip                                 \
					    --verbose                              \
					    --file  $$lokaldir.tar.gz *

#---------- zip ------------------------------------------
zip:
					lokaldir=`pwd`; lokaldir=$${lokaldir##*/}; \
					zip -r  $$lokaldir.zip * -x $(ZIP_EXCLUDE)

#---------- clear up -------------------------------------
clean:
				rm  --force  $(EXECUTABLE) $(OBJECTS) $(PREREQUISITES)
 
