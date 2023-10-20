﻿namespace App.Utils {
    public static class ObjectStore {
        private static object[] objects;
        private static int[] handles;
        private static int nextHandleIndex;

        static ObjectStore() {
            Init(500000);
        }

        static void Init(int maxObjects) {
            objects = new object[maxObjects + 1];
            handles = new int[maxObjects];
            for (int i = 0, handle = maxObjects;
                 i < maxObjects;
                 ++i, --handle) {
                handles[i] = handle;
            }

            nextHandleIndex = maxObjects - 1;
        }

        public static int Store(object obj) {
            lock (objects) {
                int handle = handles[nextHandleIndex];
                nextHandleIndex--;

                objects[handle] = obj;
                return handle;
            }
        }

        public static object Get(int handle) {
            return objects[handle];
        }

        public static void Remove(int handle) {
            lock (objects) {
                objects[handle] = null;
                nextHandleIndex++;
                handles[nextHandleIndex] = handle;
            }
        }
    }
}