MAKE     := make
SRCDIR   := src


.PHONY: all depends syntax ctags install uninstall clean cleanobj
all:
	$(MAKE) -C $(SRCDIR)

depends:
	$(MAKE) -C $(SRCDIR) $@

syntax:
	$(MAKE) -C $(SRCDIR) $@

ctags:
	$(MAKE) -C $(SRCDIR) $@

install:
	$(MAKE) -C $(SRCDIR) $@

uninstall:
	$(MAKE) -C $(SRCDIR) $@

clean:
	$(MAKE) -C $(SRCDIR) $@

cleanobj:
	$(MAKE) -C $(SRCDIR) $@
