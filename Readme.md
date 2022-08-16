## Install Perfetto
Build Perfetto from source
https://perfetto.dev/docs/quickstart/linux-tracing

Add Perfetto executable file to PATH
```shell
sudo ln -s $(pwd)/out/linux/tracebox /usr/bin/tracebox
```

Capture trace:
```shell
sudo tracebox -o /mnt/hgfs/workspace/trace_file.perfetto-trace --txt -c scheduling.cfg
```

## Build and run demo
```
mkdir build
cd build
cmake ..
make
./build/PerfettoLearn
```

## Review trace
https://ui.perfetto.dev/#!/viewer