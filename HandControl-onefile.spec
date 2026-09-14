# -*- mode: python ; coding: utf-8 -*-
# One-file build: produces dist/HandControl.exe with nothing to install.
#
# hardware_config.json and pir_recordings/ are deliberately NOT bundled -- the
# app reads and writes them beside the EXE (see APP_DIR in
# simple_hand_control.py) so presets and takes you save survive a restart.
# Ship the whole HandControl folder, not the bare .exe.
from PyInstaller.utils.hooks import collect_all

datas = []
binaries = []
hiddenimports = []
tmp_ret = collect_all('customtkinter')
datas += tmp_ret[0]; binaries += tmp_ret[1]; hiddenimports += tmp_ret[2]

a = Analysis(
    ['simple_hand_control.py'],
    pathex=[],
    binaries=binaries,
    datas=datas,
    hiddenimports=hiddenimports,
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
    optimize=0,
)
pyz = PYZ(a.pure)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name='HandControl',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    # UPX off: it buys a few MB and is a reliable way to get the EXE flagged by
    # antivirus on a machine that has never seen it before.
    upx=False,
    runtime_tmpdir=None,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)
