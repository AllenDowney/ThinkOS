PDFFLAGS = -dCompatibilityLevel=1.4 -dPDFSETTINGS=/prepress \
           -dCompressPages=true -dUseFlateCompression=true  \
           -dEmbedAllFonts=true -dSubsetFonts=true -dMaxSubsetPct=100


all:	book.tex
	pdflatex book
	makeindex book.idx
	pdflatex book
	mv book.pdf thinkos.pdf
	evince thinkos.pdf

HEVEABUILDLOG=build.log


hevea:
	sed 's/\(figs\/[^.]*\).\(pdf\|png\)/\1.eps/' book.tex > thinkos.tex
	rm -rf html
	mkdir html
	hevea macros.hva -O -e latexonly htmlonly thinkos 2>&1 | tee ${HEVEABUILDLOG}
# the following greps are a kludge to prevent imagen from seeing
# the definitions in latexonly, and to avoid headers on the images
	grep -v latexonly thinkos.image.tex > a; mv a thinkos.image.tex
	sed s/\\\\usepackage{fancyhdr}// < thinkos.image.tex > a; mv a thinkos.image.tex
	imagen -png thinkos
	hacha thinkos.html
	cp up.png next.png back.png html
	cp custom.css thinkos.css
	mv index.html thinkos.css thinkos*.html thinkos*.png *motif.gif html

DEST = /home/downey/public_html/greent/thinkos

distrib:
	rm -rf dist
	mkdir dist
	rsync -a thinkos.pdf html dist
	rsync -a dist/* $(DEST)
	chmod -R o+r $(DEST)/*
	cd $(DEST)/..; sh back

plastex:
	# Before running plastex, we need the current directory in PYTHONPATH
	# export PYTHONPATH=$PYTHONPATH:.
	rm -rf /home/downey/thinkos/trunk/book/.svn
	plastex --renderer=DocBook --theme=book --image-resolution=300 --filename=book.xml book.tex
	rm -rf /home/downey/thinkos/trunk/book/.svn

xxe:
	xmlcopyeditor ~/ThinkOS/book/book/book.xml &

lint:
	xmllint -noout book/book.xml

OREILLY = atlas

oreilly:
	rsync -a book/ $(OREILLY)
	rsync -a figs/* $(OREILLY)/figs/
	cd $(OREILLY); git add .
	cd $(OREILLY); git commit -m "Automated check in."
	cd $(OREILLY); git push

clean:
	rm -f *~ *.aux *.log *.dvi *.idx *.ilg *.ind *.toc


pdfpextr = \
    gs -sDEVICE=pdfwrite -dNOPAUSE -dBATCH -dSAFER \
       -dFirstPage=$(1) \
       -dLastPage=$(2) \
       -sOutputFile=$(4) \
       $(3)

split:
	$(call pdfpextr,5,7,thinkos.pdf,chap00.pdf)
	$(call pdfpextr,13,20,thinkos.pdf,chap01.pdf)
	$(call pdfpextr,21,26,thinkos.pdf,chap02.pdf)
	$(call pdfpextr,27,34,thinkos.pdf,chap03.pdf)
	$(call pdfpextr,35,42,thinkos.pdf,chap04.pdf)
	$(call pdfpextr,43,50,thinkos.pdf,chap05.pdf)
	$(call pdfpextr,51,56,thinkos.pdf,chap06.pdf)
	$(call pdfpextr,57,68,thinkos.pdf,chap07.pdf)
	$(call pdfpextr,69,74,thinkos.pdf,chap08.pdf)
	$(call pdfpextr,75,82,thinkos.pdf,chap09.pdf)
	$(call pdfpextr,83,94,thinkos.pdf,chap10.pdf)
	$(call pdfpextr,95,101,thinkos.pdf,chap11.pdf)

