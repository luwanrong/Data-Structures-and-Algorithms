
dataps.dll: dlldata.obj data_p.obj data_i.obj
	link /dll /out:dataps.dll /def:dataps.def /entry:DllMain dlldata.obj data_p.obj data_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del dataps.dll
	@del dataps.lib
	@del dataps.exp
	@del dlldata.obj
	@del data_p.obj
	@del data_i.obj
