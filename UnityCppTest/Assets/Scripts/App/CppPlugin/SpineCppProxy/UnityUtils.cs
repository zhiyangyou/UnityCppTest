namespace App
{
    public static class UnityUtils
    {
        public static bool IsUnityEditor()
        {
#if UNITY_EDITOR
            return true;
#else
            return false;
#endif
        }
    }
}