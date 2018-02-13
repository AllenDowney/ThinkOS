LATEX = latex

DVIPS = dvips

PDFFLAGS = -dCompatibilityLevel=1.4 -dPDFSETTINGS=/prepress \
           -dCompressPages=true -dUseFlateCompression=true  \
           -dEmbedAllFonts=true -dSubsetFonts=true -dMaxSubsetPct=100


%.dvi: %.tex
	$(LATEX) $<

%.ps: %.dvi
	$(DVIPS) -o $@ $<

%.pdf: %.ps
	ps2pdf $(PDFFLAGS) $<

all:	book.tex
	pdflatex book
	makeindex book.idx
	mv book.pdf thinkos.pdf
	evince thinkos.pdf

hevea:
	sed 's/\(figs\/[^.]*\).\(pdf\|png\)/\1.eps/' book.tex > thinkos.tex
	rm -rf html
	mkdir html
	hevea -O -e latexonly htmlonly thinkos
	imagen -png thinkos
	hacha thinkos.html
	cp up.png next.png back.png html
	mv index.html thinkos.css thinkos*.html thinkos*.png *motif.gif html

DEST = /home/downey/public_html/greent/thinkos

distrib:
	rm -rf dist
	mkdir dist dist/tex dist/tex/figs
	rsync -a thinkos.pdf html dist
	rsync -a Makefile book.tex latexonly htmlonly dist/tex
	# rsync -a figs/*.fig figs/*.eps dist/tex/figs
	cd dist; zip -r thinkos.tex.zip tex
	cd dist; zip -r thinkos.html.zip html
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
	~/Downloads/xxe-perso-4_8_0/bin/xxe book/book.xml

vector:
	plastex --renderer=DocBook --theme=book --vector-imager=dvisvgm --filename=book.xml book.tex

small: small.tex
	plastex --renderer=DocBook --theme=book --image-resolution=300 --filename=small.xml small.tex

sample:
	plastex --renderer=DocBook --theme=book --image-resolution=300 --image-scale-factor=0.25 --filename=sample2e.xml sample2e.tex
	~/Downloads/xxe-perso-4_8_0/bin/xxe sample2e/sample2e.xml

oreilly:
	rsync -a book/ ~/oreilly
	rsync -a figs/* ~/oreilly/figs
	cp thinkos.pdf ~/oreilly/pdf

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

