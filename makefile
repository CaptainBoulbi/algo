clean :
	for i in $$(find -name "Makefile"); do make clean -C $${i%/*} >/dev/null; done

push :
	git push gh && git push bbsrv

install : clean


.PHONY : push clean install
