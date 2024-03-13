
default: all

.DEFAULT:
	make clean
	cd src && $(MAKE) $@

clean:
	find . -type d -name 'build' -exec rm -rf {} +
	find . -type f -name 'cookserver' -exec rm -r {} \;

.PHONY: clean
