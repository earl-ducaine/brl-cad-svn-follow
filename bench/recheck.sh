#!/bin/sh
# A Shell script to re-check the most recent results of the benchmark
#  @(#)$Header$ (BRL)

# Ensure /bin/sh
export PATH || (echo "This isn't sh."; sh $0 $*; kill $$)

eval `machinetype.sh -b`	# sets MACHINE, UNIXTYPE, HAS_TCP
if test -f ../.util.$MACHINE/pixdiff
then
	PIXDIFF=../.util.$MACHINE/pixdiff
	PIX_FB=../.util.$MACHINE/pix-fb
else
	if test -f ../util/pixdiff
	then
		PIXDIFF=../util/pixdiff
		PIX_FB=../util/pix-fb
	else
		echo "Can't find pixdiff"
		exit 1
	fi
fi

# Alliant NFS hack
if test x${MACHINE} = xfx
then
	cp ${PIXDIFF} /tmp/pixdiff
	cp ${PIX_FB} /tmp/pix-fb
	PIXDIFF=/tmp/pixdiff
	PIX_FB=/tmp/pix-fb
fi

echo +++++ moss.pix
${PIXDIFF} ../pix/moss.pix moss.pix | ${PIX_FB}

echo +++++ world.pix
${PIXDIFF} ../pix/world.pix world.pix  | ${PIX_FB}

echo +++++ star.pix
${PIXDIFF} ../pix/star.pix star.pix  | ${PIX_FB}

echo +++++ bldg391.pix
${PIXDIFF} ../pix/bldg391.pix bldg391.pix  | ${PIX_FB}

echo +++++ m35.pix
${PIXDIFF} ../pix/m35.pix m35.pix  | ${PIX_FB}
