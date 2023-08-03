PROJECTNAME=algo

clean :
	for i in $$(find -name "Makefile"); do make clean -C $${i%/*} >/dev/null; done
	rm -f $(PROJECTNAME).tgz

push :
	git push gh && git push bbsrv

dist : clean
	$(info /!\ project folder has to be named $(PROJECTNAME) /!\ )
	cd .. && tar zcvf temp_archive.tgz $(PROJECTNAME) >/dev/null
	mv ../temp_archive.tgz $(PROJECTNAME).tgz

install : dist
	mv $(PROJECTNAME).tgz ../opt/archive
	cd .. && rm -rf $(PROJECTNAME)


.PHONY : clean push dist install
