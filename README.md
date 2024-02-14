# SharedSoundServer

This project is meant to be an Open Source [SoundWire](https://play.google.com/store/apps/details?id=com.georgie.SoundWireFree) alternative.

The server is already working, though there is still no client to use yet, and there is no security builting to it, which is fine if you want to use it only in your local network.

## Usage

All it does is basically get the audio from the audio server of your system (which currently only supports pulse audio) and sends it raw through TCP connection, which is meant to be consumed by a client and so that you can connect the sound of you computer to another device on your network.

## Building

Once you have pulse audio installed your system you should be able to just use:

```console
$ make clean build
```

## Support

At this current moment this project only supports linux with pulse audio.

## Goals

- Adding some kind of compression to the audio so that it can work faster.
- Adding an android client to consume it.

