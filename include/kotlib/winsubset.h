#if !defined(KOTLIB_WINSUBSET_H) && (defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__))
#define KOTLIB_WINSUBSET_H


// #  define OEMRESOURCE
#if !(defined(WIN32_LEAN_AND_MEAN) || defined(KOTLIB_WINSUBSET_DISABLE_WIN32_LEAN_AND_MEAN))
#  define WIN32_LEAN_AND_MEAN
#  define KOTLIB_WINSUBSET_WIN32_LEAN_AND_MEAN_IS_NOT_DEFINED
#endif
#if !(defined(NOGDICAPMASKS) || defined(KOTLIB_WINSUBSET_GDICAPMASKS))
#  define NOGDICAPMASKS
#  define KOTLIB_WINSUBSET_NOGDICAPMASKS_IS_NOT_DEFINED
#endif
#if !(defined(NOVIRTUALKEYCODES) || defined(KOTLIB_WINSUBSET_VIRTUALKEYCODES))
#  define NOVIRTUALKEYCODES
#  define KOTLIB_WINSUBSET_NOVIRTUALKEYCODES_IS_NOT_DEFINED
#endif
#if !(defined(NOWINMESSAGES) || defined(KOTLIB_WINSUBSET_WINMESSAGES))
#  define NOWINMESSAGES
#  define KOTLIB_WINSUBSET_NOWINMESSAGES_IS_NOT_DEFINED
#endif
#if !(defined(NOWINSTYLES) || defined(KOTLIB_WINSUBSET_WINSTYLES))
#  define NOWINSTYLES
#  define KOTLIB_WINSUBSET_NOWINSTYLES_IS_NOT_DEFINED
#endif
#if !(defined(NOSYSMETRICS) || defined(KOTLIB_WINSUBSET_SYSMETRICS))
#  define NOSYSMETRICS
#  define KOTLIB_WINSUBSET_NOSYSMETRICS_IS_NOT_DEFINED
#endif
#if !(defined(NOMENUS) || defined(KOTLIB_WINSUBSET_MENUS))
#  define NOMENUS
#  define KOTLIB_WINSUBSET_NOMENUS_IS_NOT_DEFINED
#endif
#if !(defined(NOICONS) || defined(KOTLIB_WINSUBSET_ICONS))
#  define NOICONS
#  define KOTLIB_WINSUBSET_NOICONS_IS_NOT_DEFINED
#endif
#if !(defined(NOKEYSTATES) || defined(KOTLIB_WINSUBSET_KEYSTATES))
#  define NOKEYSTATES
#  define KOTLIB_WINSUBSET_NOKEYSTATES_IS_NOT_DEFINED
#endif
#if !(defined(NOSYSCOMMANDS) || defined(KOTLIB_WINSUBSET_SYSCOMMANDS))
#  define NOSYSCOMMANDS
#  define KOTLIB_WINSUBSET_NOSYSCOMMANDS_IS_NOT_DEFINED
#endif
#if !(defined(NORASTEROPS) || defined(KOTLIB_WINSUBSET_RASTEROPS))
#  define NORASTEROPS
#  define KOTLIB_WINSUBSET_NORASTEROPS_IS_NOT_DEFINED
#endif
#if !(defined(NOSHOWWINDOW) || defined(KOTLIB_WINSUBSET_SHOWWINDOW))
#  define NOSHOWWINDOW
#  define KOTLIB_WINSUBSET_NOSHOWWINDOW_IS_NOT_DEFINED
#endif
#if !(defined(NOATOM) || defined(KOTLIB_WINSUBSET_ATOM))
#  define NOATOM
#  define KOTLIB_WINSUBSET_NOATOM_IS_NOT_DEFINED
#endif
#if !(defined(NOCLIPBOARD) || defined(KOTLIB_WINSUBSET_CLIPBOARD))
#  define NOCLIPBOARD
#  define KOTLIB_WINSUBSET_NOCLIPBOARD_IS_NOT_DEFINED
#endif
#if !(defined(NOCOLOR) || defined(KOTLIB_WINSUBSET_COLOR))
#  define NOCOLOR
#  define KOTLIB_WINSUBSET_NOCOLOR_IS_NOT_DEFINED
#endif
#if !(defined(NOCTLMGR) || defined(KOTLIB_WINSUBSET_CTLMGR))
#  define NOCTLMGR
#  define KOTLIB_WINSUBSET_NOCTLMGR_IS_NOT_DEFINED
#endif
#if !(defined(NODRAWTEXT) || defined(KOTLIB_WINSUBSET_DRAWTEXT))
#  define NODRAWTEXT
#  define KOTLIB_WINSUBSET_NODRAWTEXT_IS_NOT_DEFINED
#endif
#if !(defined(NOGDI) || defined(KOTLIB_WINSUBSET_GDI))
#  define NOGDI
#  define KOTLIB_WINSUBSET_NOGDI_IS_NOT_DEFINED
#endif
#if !(defined(NOKERNEL) || defined(KOTLIB_WINSUBSET_KERNEL))
#  define NOKERNEL
#  define KOTLIB_WINSUBSET_NOKERNEL_IS_NOT_DEFINED
#endif
#if !(defined(NOUSER) || defined(KOTLIB_WINSUBSET_USER))
#  define NOUSER
#  define KOTLIB_WINSUBSET_NOUSER_IS_NOT_DEFINED
#endif
#if !(defined(NONLS) || defined(KOTLIB_WINSUBSET_NLS))
#  define NONLS
#  define KOTLIB_WINSUBSET_NONLS_IS_NOT_DEFINED
#endif
#if !(defined(NOMB) || defined(KOTLIB_WINSUBSET_MB))
#  define NOMB
#  define KOTLIB_WINSUBSET_NOMB_IS_NOT_DEFINED
#endif
#if !(defined(NOMEMMGR) || defined(KOTLIB_WINSUBSET_MEMMGR))
#  define NOMEMMGR
#  define KOTLIB_WINSUBSET_NOMEMMGR_IS_NOT_DEFINED
#endif
#if !(defined(NOMETAFILE) || defined(KOTLIB_WINSUBSET_METAFILE))
#  define NOMETAFILE
#  define KOTLIB_WINSUBSET_NOMETAFILE_IS_NOT_DEFINED
#endif
#if !(defined(NOMINMAX) || defined(KOTLIB_WINSUBSET_MINMAX))
#  define NOMINMAX
#  define KOTLIB_WINSUBSET_NOMINMAX_IS_NOT_DEFINED
#endif
#if !(defined(NOMSG) || defined(KOTLIB_WINSUBSET_MSG))
#  define NOMSG
#  define KOTLIB_WINSUBSET_NOMSG_IS_NOT_DEFINED
#endif
#if !(defined(NOOPENFILE) || defined(KOTLIB_WINSUBSET_OPENFILE))
#  define NOOPENFILE
#  define KOTLIB_WINSUBSET_NOOPENFILE_IS_NOT_DEFINED
#endif
#if !(defined(NOSCROLL) || defined(KOTLIB_WINSUBSET_SCROLL))
#  define NOSCROLL
#  define KOTLIB_WINSUBSET_NOSCROLL_IS_NOT_DEFINED
#endif
#if !(defined(NOSERVICE) || defined(KOTLIB_WINSUBSET_SERVICE))
#  define NOSERVICE
#  define KOTLIB_WINSUBSET_NOSERVICE_IS_NOT_DEFINED
#endif
#if !(defined(NOSOUND) || defined(KOTLIB_WINSUBSET_SOUND))
#  define NOSOUND
#  define KOTLIB_WINSUBSET_NOSOUND_IS_NOT_DEFINED
#endif
#if !(defined(NOTEXTMETRIC) || defined(KOTLIB_WINSUBSET_TEXTMETRIC))
#  define NOTEXTMETRIC
#  define KOTLIB_WINSUBSET_NOTEXTMETRIC_IS_NOT_DEFINED
#endif
#if !(defined(NOWH) || defined(KOTLIB_WINSUBSET_WH))
#  define NOWH
#  define KOTLIB_WINSUBSET_NOWH_IS_NOT_DEFINED
#endif
#if !(defined(NOWINOFFSETS) || defined(KOTLIB_WINSUBSET_WINOFFSETS))
#  define NOWINOFFSETS
#  define KOTLIB_WINSUBSET_NOWINOFFSETS_IS_NOT_DEFINED
#endif
#if !(defined(NOCOMM) || defined(KOTLIB_WINSUBSET_COMM))
#  define NOCOMM
#  define KOTLIB_WINSUBSET_NOCOMM_IS_NOT_DEFINED
#endif
#if !(defined(NOKANJI) || defined(KOTLIB_WINSUBSET_KANJI))
#  define NOKANJI
#  define KOTLIB_WINSUBSET_NOKANJI_IS_NOT_DEFINED
#endif
#if !(defined(NOHELP) || defined(KOTLIB_WINSUBSET_HELP))
#  define NOHELP
#  define KOTLIB_WINSUBSET_NOHELP_IS_NOT_DEFINED
#endif
#if !(defined(NOPROFILER) || defined(KOTLIB_WINSUBSET_PROFILER))
#  define NOPROFILER
#  define KOTLIB_WINSUBSET_NOPROFILER_IS_NOT_DEFINED
#endif
#if !(defined(NODEFERWINDOWPOS) || defined(KOTLIB_WINSUBSET_DEFERWINDOWPOS))
#  define NODEFERWINDOWPOS
#  define KOTLIB_WINSUBSET_NODEFERWINDOWPOS_IS_NOT_DEFINED
#endif
#if !(defined(NOMCX) || defined(KOTLIB_WINSUBSET_MCX))
#  define NOMCX
#  define KOTLIB_WINSUBSET_NOMCX_IS_NOT_DEFINED
#endif

#include <windows.h>

#ifdef KOTLIB_WINSUBSET_WIN32_LEAN_AND_MEAN_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_WIN32_LEAN_AND_MEAN_IS_NOT_DEFINED
#  undef WIN32_LEAN_AND_MEAN
#endif
#ifdef KOTLIB_WINSUBSET_NOGDICAPMASKS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOGDICAPMASKS_IS_NOT_DEFINED
#  undef NOGDICAPMASKS
#endif
#ifdef KOTLIB_WINSUBSET_NOVIRTUALKEYCODES_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOVIRTUALKEYCODES_IS_NOT_DEFINED
#  undef NOVIRTUALKEYCODES
#endif
#ifdef KOTLIB_WINSUBSET_NOWINMESSAGES_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOWINMESSAGES_IS_NOT_DEFINED
#  undef NOWINMESSAGES
#endif
#ifdef KOTLIB_WINSUBSET_NOWINSTYLES_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOWINSTYLES_IS_NOT_DEFINED
#  undef NOWINSTYLES
#endif
#ifdef KOTLIB_WINSUBSET_NOSYSMETRICS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSYSMETRICS_IS_NOT_DEFINED
#  undef NOSYSMETRICS
#endif
#ifdef KOTLIB_WINSUBSET_NOMENUS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMENUS_IS_NOT_DEFINED
#  undef NOMENUS
#endif
#ifdef KOTLIB_WINSUBSET_NOICONS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOICONS_IS_NOT_DEFINED
#  undef NOICONS
#endif
#ifdef KOTLIB_WINSUBSET_NOKEYSTATES_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOKEYSTATES_IS_NOT_DEFINED
#  undef NOKEYSTATES
#endif
#ifdef KOTLIB_WINSUBSET_NOSYSCOMMANDS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSYSCOMMANDS_IS_NOT_DEFINED
#  undef NOSYSCOMMANDS
#endif
#ifdef KOTLIB_WINSUBSET_NORASTEROPS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NORASTEROPS_IS_NOT_DEFINED
#  undef NORASTEROPS
#endif
#ifdef KOTLIB_WINSUBSET_NOSHOWWINDOW_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSHOWWINDOW_IS_NOT_DEFINED
#  undef NOSHOWWINDOW
#endif
#ifdef KOTLIB_WINSUBSET_NOATOM_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOATOM_IS_NOT_DEFINED
#  undef NOATOM
#endif
#ifdef KOTLIB_WINSUBSET_NOCLIPBOARD_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOCLIPBOARD_IS_NOT_DEFINED
#  undef NOCLIPBOARD
#endif
#ifdef KOTLIB_WINSUBSET_NOCOLOR_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOCOLOR_IS_NOT_DEFINED
#  undef NOCOLOR
#endif
#ifdef KOTLIB_WINSUBSET_NOCTLMGR_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOCTLMGR_IS_NOT_DEFINED
#  undef NOCTLMGR
#endif
#ifdef KOTLIB_WINSUBSET_NODRAWTEXT_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NODRAWTEXT_IS_NOT_DEFINED
#  undef NODRAWTEXT
#endif
#ifdef KOTLIB_WINSUBSET_NOGDI_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOGDI_IS_NOT_DEFINED
#  undef NOGDI
#endif
#ifdef KOTLIB_WINSUBSET_NOKERNEL_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOKERNEL_IS_NOT_DEFINED
#  undef NOKERNEL
#endif
#ifdef KOTLIB_WINSUBSET_NOUSER_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOUSER_IS_NOT_DEFINED
#  undef NOUSER
#endif
#ifdef KOTLIB_WINSUBSET_NONLS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NONLS_IS_NOT_DEFINED
#  undef NONLS
#endif
#ifdef KOTLIB_WINSUBSET_NOMB_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMB_IS_NOT_DEFINED
#  undef NOMB
#endif
#ifdef KOTLIB_WINSUBSET_NOMEMMGR_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMEMMGR_IS_NOT_DEFINED
#  undef NOMEMMGR
#endif
#ifdef KOTLIB_WINSUBSET_NOMETAFILE_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMETAFILE_IS_NOT_DEFINED
#  undef NOMETAFILE
#endif
#ifdef KOTLIB_WINSUBSET_NOMINMAX_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMINMAX_IS_NOT_DEFINED
#  undef NOMINMAX
#endif
#ifdef KOTLIB_WINSUBSET_NOMSG_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMSG_IS_NOT_DEFINED
#  undef NOMSG
#endif
#ifdef KOTLIB_WINSUBSET_NOOPENFILE_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOOPENFILE_IS_NOT_DEFINED
#  undef NOOPENFILE
#endif
#ifdef KOTLIB_WINSUBSET_NOSCROLL_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSCROLL_IS_NOT_DEFINED
#  undef NOSCROLL
#endif
#ifdef KOTLIB_WINSUBSET_NOSERVICE_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSERVICE_IS_NOT_DEFINED
#  undef NOSERVICE
#endif
#ifdef KOTLIB_WINSUBSET_NOSOUND_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOSOUND_IS_NOT_DEFINED
#  undef NOSOUND
#endif
#ifdef KOTLIB_WINSUBSET_NOTEXTMETRIC_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOTEXTMETRIC_IS_NOT_DEFINED
#  undef NOTEXTMETRIC
#endif
#ifdef KOTLIB_WINSUBSET_NOWH_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOWH_IS_NOT_DEFINED
#  undef NOWH
#endif
#ifdef KOTLIB_WINSUBSET_NOWINOFFSETS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOWINOFFSETS_IS_NOT_DEFINED
#  undef NOWINOFFSETS
#endif
#ifdef KOTLIB_WINSUBSET_NOCOMM_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOCOMM_IS_NOT_DEFINED
#  undef NOCOMM
#endif
#ifdef KOTLIB_WINSUBSET_NOKANJI_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOKANJI_IS_NOT_DEFINED
#  undef NOKANJI
#endif
#ifdef KOTLIB_WINSUBSET_NOHELP_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOHELP_IS_NOT_DEFINED
#  undef NOHELP
#endif
#ifdef KOTLIB_WINSUBSET_NOPROFILER_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOPROFILER_IS_NOT_DEFINED
#  undef NOPROFILER
#endif
#ifdef KOTLIB_WINSUBSET_NODEFERWINDOWPOS_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NODEFERWINDOWPOS_IS_NOT_DEFINED
#  undef NODEFERWINDOWPOS
#endif
#ifdef KOTLIB_WINSUBSET_NOMCX_IS_NOT_DEFINED
#  undef KOTLIB_WINSUBSET_NOMCX_IS_NOT_DEFINED
#  undef NOMCX
#endif


#endif  // !defined(KOTLIB_WINSUBSET_H) && (defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__))
