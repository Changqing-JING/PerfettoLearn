## Install Perfetto
https://perfetto.dev/docs/quickstart/linux-tracing

Capture trace:
```shell
out/linux/tracebox -o /mnt/hgfs/workspace/trace_file.perfetto-trace --txt -c test/configs/scheduling.cfg
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