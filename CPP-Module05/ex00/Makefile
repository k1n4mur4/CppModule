MAKEFILE_VERSION	:=	1.0
BANNER  = \n \033[38;5;51m██████\033[38;5;240m╗   \033[38;5;51m██\033[38;5;240m╗    \033[38;5;51m██\033[38;5;240m╗     \033[38;5;51m███\033[38;5;240m╗   \033[38;5;51m███\033[38;5;240m╗ \033[38;5;51m██████\033[38;5;240m╗ \033[38;5;51m██████\033[38;5;240m╗ \033[38;5;51m██\033[38;5;240m╗   \033[38;5;51m██\033[38;5;240m╗\033[38;5;51m██\033[38;5;240m╗     \033[38;5;51m███████\033[38;5;240m╗\n\033[38;5;51m██\033[38;5;240m╔════╝   \033[38;5;51m██\033[38;5;240m║    \033[38;5;51m██\033[38;5;240m║     \033[38;5;51m████\033[38;5;240m╗ \033[38;5;51m████\033[38;5;240m║\033[38;5;51m██\033[38;5;240m╔═══\033[38;5;51m██\033[38;5;240m╗\033[38;5;51m██\033[38;5;240m╔══\033[38;5;51m██\033[38;5;240m╗\033[38;5;51m██\033[38;5;240m║   \033[38;5;51m██\033[38;5;240m║\033[38;5;51m██\033[38;5;240m║     \033[38;5;51m██\033[38;5;240m╔════╝\n\033[38;5;39m██\033[38;5;238m║      \033[38;5;39m██████\033[38;5;238m╗\033[38;5;39m██████\033[38;5;238m╗   \033[38;5;39m██\033[38;5;238m╔\033[38;5;39m████\033[38;5;238m╔\033[38;5;39m██\033[38;5;238m║\033[38;5;39m██\033[38;5;238m║   \033[38;5;39m██\033[38;5;238m║\033[38;5;39m██\033[38;5;238m║  \033[38;5;39m██\033[38;5;238m║\033[38;5;39m██\033[38;5;238m║   \033[38;5;39m██\033[38;5;238m║\033[38;5;39m██\033[38;5;238m║     \033[38;5;39m█████\033[38;5;238m╗  \n\033[38;5;33m██\033[38;5;237m║      ╚═\033[38;5;33m██\033[38;5;237m╔═╝╚═\033[38;5;33m██\033[38;5;237m╔═╝   \033[38;5;33m██\033[38;5;237m║╚\033[38;5;33m██\033[38;5;237m╔╝\033[38;5;33m██\033[38;5;237m║\033[38;5;33m██\033[38;5;237m║   \033[38;5;33m██\033[38;5;237m║\033[38;5;33m██\033[38;5;237m║  \033[38;5;33m██\033[38;5;237m║\033[38;5;33m██\033[38;5;237m║   \033[38;5;33m██\033[38;5;237m║\033[38;5;33m██\033[38;5;237m║     \033[38;5;33m██\033[38;5;237m╔══╝  \n\033[38;5;236m╚\033[38;5;27m██████\033[38;5;236m╗   \033[38;5;27m██\033[38;5;236m║    \033[38;5;27m██\033[38;5;236m║     \033[38;5;27m██\033[38;5;236m║ ╚═╝ \033[38;5;27m██\033[38;5;236m║╚\033[38;5;27m██████\033[38;5;236m╔╝\033[38;5;27m██████\033[38;5;236m╔╝╚\033[38;5;27m██████\033[38;5;236m╔╝\033[38;5;27m██████\033[38;5;236m╗ \033[38;5;27m███████\033[38;5;236m╗\n \033[38;5;235m╚═════╝   ╚═╝    ╚═╝     ╚═╝     ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝ \033[1;3;38;5;240mMakefile v$(MAKEFILE_VERSION)\033[0m\n

override TIMESTAMP	:=	$(shell date +%s 2>/dev/null || echo "0")

ifneq ($(QUIET),true)
	override QUIET	:=	false
endif

#? Compiler and Linker
NAME			:=	bureaucrat
CXX				:=	c++
RM				:=	rm -rf

#? Compiler Flags (split)
REQFLAGS		:=	-std=c++98 -pedantic
WARNFLAGS		:=	-Wall -Wextra -Werror
OPTFLAGS		:=
LDFLAGS			:=
CXXFLAGS		:=	$(REQFLAGS) $(WARNFLAGS) $(OPTFLAGS)

#? Compiler info
override CXX_VERSION	:=	$(shell $(CXX) -dumpfullversion -dumpversion 2>/dev/null || echo "unknown")

#? Detect PLATFORM and ARCH
ARCH		?= $(shell uname -m || echo unknown)

ifeq ($(shell uname -s),Darwin)
	PLATFORM		:=	macOS
	THREADS			:=	$(shell sysctl -n hw.ncpu || echo 1)
else
	PLATFORM		:=	$(shell uname -s || echo unknown)
	THREADS			:=	$(shell getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
endif

#? Use all CPU cores
MAKEFLAGS	+= --jobs=$(THREADS) --no-print-directory

ifeq ($(VERBOSE),true)
	override VERBOSE	:=	false
else
	override VERBOSE	:=	true
endif

#? The Directories and Extensions
SRCDIR			:=	src
BUILDDIR		:=	obj
TARGETDIR		:=	bin
SRCEXT			:=	cpp
OBJEXT			:=	o

#? Sources and Objects
SOURCES			:=	$(SRCDIR)/main.cpp \
					$(SRCDIR)/Bureaucrat.cpp

OBJECTS			:=	$(patsubst $(SRCDIR)/%.$(SRCEXT),$(BUILDDIR)/%.$(OBJEXT),$(SOURCES))

#? Includes
INC				:=	-I $(SRCDIR)

#? Setup percentage progress
SOURCE_COUNT	:=	$(words $(SOURCES))
P				:=	%%

ifeq ($(VERBOSE),true)
	override SUPPRESS	:=	> /dev/null 2> /dev/null
else
	override SUPPRESS	:=
endif

#? Default Make
all: | info directories $(TARGETDIR)/$(NAME)
	@END=$$(date +%s 2>/dev/null || echo "0"); \
	ELAPSED=$$((END - $(TIMESTAMP))); \
	MINS=$$((ELAPSED / 60)); \
	SECS=$$((ELAPSED % 60)); \
	if [ $$MINS -gt 0 ]; then \
		printf "\n\033[1;92mBuild complete in \033[92m(\033[97m%dm:%02ds\033[92m)\033[0m\n" $$MINS $$SECS; \
	else \
		printf "\n\033[1;92mBuild complete in \033[92m(\033[97m%ds\033[92m)\033[0m\n" $$SECS; \
	fi

ifneq ($(QUIET),true)
info:
	@printf " $(BANNER)\n"
	@printf "\033[1;92mPLATFORM     \033[1;93m?| \033[0m$(PLATFORM)\n"
	@printf "\033[1;96mARCH         \033[1;93m?| \033[0m$(ARCH)\n"
	@printf "\033[1;93mCXX          \033[1;93m?| \033[0m$(CXX) \033[1;93m(\033[97m$(CXX_VERSION)\033[93m)\n"
	@printf "\033[1;94mTHREADS      \033[1;94m:| \033[0m$(if $(THREADS),$(THREADS),(none))\n"
	@printf "\033[1;91mREQFLAGS     \033[1;91m!| \033[0m$(if $(REQFLAGS),$(REQFLAGS),(none))\n"
	@printf "\033[1;93mWARNFLAGS    \033[1;94m:| \033[0m$(if $(WARNFLAGS),$(WARNFLAGS),(none))\n"
	@printf "\033[1;95mOPTFLAGS     \033[1;94m:| \033[0m$(if $(OPTFLAGS),$(OPTFLAGS),(none))\n"
	@printf "\033[1;96mLDFLAGS      \033[1;94m:| \033[0m$(if $(LDFLAGS),$(LDFLAGS),(none))\n"
	@printf '\033[1;97mCXXFLAGS     \033[1;92m+| \033[0m$$(REQFLAGS) $$(WARNFLAGS) $$(OPTFLAGS)\n'
	@printf "\033[1;95mINCLUDES     \033[1;92m+| \033[0m$(if $(INC),$(INC),(none))\n"
	@printf "\n\033[1;92mBuilding $(NAME) \033[93m$(PLATFORM) \033[96m$(ARCH)\033[0m\n\n"
else
info:
	@true
endif

help:
	@printf " $(BANNER)\n"
	@printf "\033[1;97m$(NAME) makefile\033[0m\n"
	@printf "usage: make [target]\n\n"
	@printf "\033[1;4mTargets:\033[0m\n"
	@printf "  \033[1mall\033[0m          Compile $(NAME) (default)\n"
	@printf "  \033[1mclean\033[0m        Remove built objects\n"
	@printf "  \033[1mfclean\033[0m       Remove built objects and binary\n"
	@printf "  \033[1mre\033[0m           Rebuild from scratch\n"
	@printf "  \033[1minfo\033[0m         Display build information\n"
	@printf "  \033[1mhelp\033[0m         Show this help message\n"

#? Make the Directories
directories:
	@$(VERBOSE) || printf "mkdir -p $(TARGETDIR) $(BUILDDIR)\n"
	@mkdir -p $(TARGETDIR) $(BUILDDIR)
	@echo 0 > $(BUILDDIR)/.progress_count

#? Link
$(TARGETDIR)/$(NAME): $(OBJECTS) | directories
	@$(QUIET) || printf "\033[1;92mLinking and creating binary\033[37m...\033[0m\n"; \
	$(VERBOSE) || printf "$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^\n"; \
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ || exit 1; \
	printf "\033[1;92m100$(P) -> \033[1;37m$@ \033[1;93m(\033[1;97m$$(du -h $@ | cut -f1)\033[1;93m)\033[0m\n"

#? Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) | directories
	@$(QUIET) || printf "\033[1;97mCompiling $<\033[0m\n"; \
	$(VERBOSE) || printf "$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<\n"; \
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $< || exit 1; \
	while ! mkdir $(BUILDDIR)/.progress_lock 2>/dev/null; do sleep 0.01; done; \
	PROGRESS=$$(( $$(cat $(BUILDDIR)/.progress_count) + 1 )); \
	echo $$PROGRESS > $(BUILDDIR)/.progress_count; \
	rmdir $(BUILDDIR)/.progress_lock; \
	PERCENT=$$((PROGRESS * 100 / $(SOURCE_COUNT))); \
	printf "\033[1;92m%3d$(P) -> \033[1;37m$@\033[0m\n" $$PERCENT

#? Clean only Objects
clean:
	@printf "\033[1;91mRemoving: \033[1;97mbuilt objects...\033[0m\n"
	@$(RM) $(BUILDDIR)
	@printf "\033[1;92mClean complete.\033[0m\n"

#? Clean Objects and Binary
fclean: clean
	@printf "\033[1;91mRemoving: \033[1;97m$(TARGETDIR)/...\033[0m\n"
	@$(RM) $(TARGETDIR)
	@printf "\033[1;92mFull clean complete.\033[0m\n"

#? Rebuild
re: fclean
	@$(MAKE) all

#? Non-File Targets
.PHONY: all clean fclean re info help directories
