# vtwm-douzzer

This is a heavily hacked-on fork of the venerable X11 window
manager `vtwm` (Virtual Tab Window Manager) first released in 1990,
itself a fork of Tom LaStrange's `twm`.

`vtwm-douzzer` is forked from
(upstream)[https://sourceforge.net/p/vtwm/code/commit_browser] at commit
7c9610917663835d97ef283c82996e43b514e444 (2017-Jun-15).  See also (the
project homepage)[http://www.vtwm.org/].
Thanks to
Seth Robertson, Callum Gibson, Branden Robinson, and the late David Hawkey, for keeping the vtwm flame alight lo
these many years, and to Dana Chee and collaborators
(attending)[http://www.vtwm.org/vtwm-changelog.html] the
(mysterious birth of `vtwm`)[http://www.vtwm.org/vtwm-family.html].
More acknowledgements are called out at the end of
`vtwm.man`.

This fork adds many new control primitives for command flow, clipboard
ops, and door dynamics, and the ability to execute arbitrary functions
and scripts through doors.  It should be fully backward-compatible
with `.vtwmrc` files, though I haven't tested to make sure.

Note, the new code is not yet bug-free.  Time and motivation
permitting, I will eventually get it fully cleaned up...

## License

MIT

## Motivation

```
-rwxr-xr-x 1 douzzer users 352400 Jul 24 11:33 vtwm
```

## Documentation

The documentation has not been updated since the fork from `vtwm`, but
some day it may be...
