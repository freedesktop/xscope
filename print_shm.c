/*
 * $XFree86$
 *
 * Copyright � 2001 Keith Packard, member of The XFree86 Project, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "scope.h"
#include "x11.h"
#include "shmscope.h"

MitshmQueryVersion (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, CONST2(2), "request length");
}

MitshmQueryVersionReply (FD fd, unsigned char *buf)
{
  short   n;
  long    m;
  long   k;

  PrintField(RBf, 0, 1, REPLY, REPLYHEADER) /* MitshmRequest reply */ ;
  if (Verbose < 1)
    return;
  PrintField(RBf, 1, 1, BOOL, "shared-pixmaps") /* shared Pixmaps */;
  printfield(buf, 2, 2, CARD16, "sequence number");
  printfield(buf, 4, 4, DVALUE4(0), "reply length");
  PrintField(buf, 8, 2, CARD16, "major-version");
  PrintField(buf, 10, 2, CARD16, "minor-version");
  PrintField(buf, 12, 2, CARD16, "uid");
  PrintField(buf, 14, 2, CARD16, "gid");
  PrintField(buf, 16, 1, CARD8, "pxiamp-fromat");
}
MitshmAttach (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, CONST2(2), "request length");
  PrintField(buf, 4, 4, CARD32, "shmseg");
  PrintField(buf, 8, 4, CARD32, "shmid");
  PrintField(buf, 12, 1, BOOL, "read-only");
}

MitshmDetach (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, CONST2(2), "request length");
  PrintField (buf, 4, 4, CARD32, "shmseg");  
}

MitshmPutImage (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, CONST2(2), "request length");
  PrintField (buf, 4, 4, DRAWABLE, "drawable");
  PrintField (buf, 8, 4, GCONTEXT, "gc");
  PrintField (buf, 12, 2, CARD16, "total-width");
  PrintField (buf, 14, 2, CARD16, "total-width");
  PrintField (buf, 16, 2, CARD16, "src-x");
  PrintField (buf, 18, 2, CARD16, "src-y");
  PrintField (buf, 20, 2, CARD16, "src-width");
  PrintField (buf, 22, 2, CARD16, "src-height");
  PrintField (buf, 24, 2, INT16, "dst-x");
  PrintField (buf, 26, 2, INT16, "dst-y");
  PrintField (buf, 28, 1, CARD8, "depth");
  PrintField (buf, 29, 1, CARD8, "format");
  PrintField (buf, 30, 1, BOOL, "send-event");
  PrintField (buf, 31, 1, CARD8, "bpad");
  PrintField (buf, 32, 4, CARD32, "shmseg");
  PrintField (buf, 36, 4, CARD32, "offset");
}

MitshmGetImage (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, DVALUE2(5+n), "request length");
  PrintField (buf, 4, 4, DRAWABLE, "drawable");
  PrintField (buf, 8, 2, INT16, "x");
  PrintField (buf, 10, 2, INT16, "y");
  PrintField (buf, 12, 2, CARD16, "width");
  PrintField (buf, 14, 2, CARD16, "height");
  PrintField (buf, 16, 4, CARD32, "planemask");
  PrintField (buf, 20, 1, CARD8, "format");
  PrintField (buf, 24, 4, CARD32, "shmseg");
  PrintField (buf, 28, 4, CARD32, "shmseg");
}

MitshmGetImageReply (FD fd, unsigned char *buf)
{
  short   n;
  long    m;
  long   k;

  PrintField(RBf, 0, 1, REPLY, REPLYHEADER) /* MitshmRequest reply */ ;
  if (Verbose < 1)
    return;
  PrintField(RBf, 1, 1, CARD8, "depth") /* shared Pixmaps */;
  printfield(buf, 2, 2, CARD16, "sequence number");
  printfield(buf, 4, 4, DVALUE4(0), "reply length");
  PrintField(buf, 8, 4, VISUALID, "visual");
}

MitshmCreatePixmap (FD fd, unsigned char *buf)
{
  PrintField (buf, 0, 1, REQUEST, REQUESTHEADER) /* MitshmRequest */ ;
  PrintField (buf, 1, 1, MITSHMREQUEST, MITSHMREQUESTHEADER) /* MitshmSwitch */ ;
  if (Verbose < 1)
    return;
  if (Verbose > 1)
    PrintField(SBf, 0, 4, CARD32, "sequence number");

  printfield(buf, 2, 2, DVALUE2(3+n), "request length");
  PrintField(buf, 4, 4, PIXMAP, "pid");
  PrintField(buf, 8, 4, DRAWABLE, "drawable");
  PrintField(buf, 12, 2, CARD16, "width");
  PrintField(buf, 14, 2, CARD16, "height");
  PrintField(buf, 16, 1, CARD8, "depth");
  PrintField(buf, 20, 4, CARD32, "shmseg");
  PrintField(buf, 24, 4, CARD32, "offset");
}
MitshmShmSegError (fd, buf)
{
}