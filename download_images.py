import os
import requests
from urllib.parse import urlparse

# 创建images目录（如果不存在）
if not os.path.exists('images'):
    os.makedirs('images')

# 算法相关图片URL（使用固定URL而不是随机生成）
algorithm_images = [
    {
        'url': 'https://images.unsplash.com/photo-1555949963-ff9fe0c870eb?q=80&w=800&h=400&auto=format&fit=crop',
        'filename': 'banner1.jpg',
        'description': '算法学习平台宣传图'
    },
    {
        'url': 'https://images.unsplash.com/photo-1517694712202-14dd9538aa97?q=80&w=800&h=400&auto=format&fit=crop',
        'filename': 'banner2.jpg',
        'description': '在线练习系统宣传图'
    },
    {
        'url': 'https://images.unsplash.com/photo-1516321318423-f06f85e504b3?q=80&w=800&h=400&auto=format&fit=crop',
        'filename': 'banner3.jpg',
        'description': '模拟考试系统宣传图'
    },
    {
        'url': 'https://images.unsplash.com/photo-1580894732444-8ecded7900cd?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'sort.jpg',
        'description': '排序算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1515879218367-8466d910aaa4?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'search.jpg',
        'description': '搜索算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1526374965328-7f61d4dc18c5?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'dynamic.jpg',
        'description': '动态规划课程封面'
    },
    # 新增算法课程图片
    {
        'url': 'https://images.unsplash.com/photo-1639322537228-f710d846310a?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'graph.jpg',
        'description': '图论算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1516259762381-22954d7d3ad2?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'string.jpg',
        'description': '字符串算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1677442136019-21780ecad995?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'ml.jpg',
        'description': '机器学习算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1551288049-bebda4e38f71?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'greedy.jpg',
        'description': '贪心算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1620712943543-bcc4688e7485?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'divide.jpg',
        'description': '分治算法课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1635070041078-e363dbe005cb?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'complexity.jpg',
        'description': '算法复杂度分析课程封面'
    },
    {
        'url': 'https://images.unsplash.com/photo-1509228468518-180dd4864904?q=80&w=300&h=200&auto=format&fit=crop',
        'filename': 'number.jpg',
        'description': '数论算法课程封面'
    }
]

def download_image(url, filename):
    """
    从URL下载图片并保存到指定文件名
    """
    try:
        # 发送GET请求获取图片
        response = requests.get(url, stream=True)
        response.raise_for_status()  # 如果请求失败则抛出异常
        
        # 保存图片到images目录
        filepath = os.path.join('images', filename)
        with open(filepath, 'wb') as file:
            for chunk in response.iter_content(chunk_size=8192):
                if chunk:
                    file.write(chunk)
        
        print(f"成功下载: {filename}")
        return True
    except Exception as e:
        print(f"下载 {filename} 失败: {str(e)}")
        return False

def main():
    """
    主函数，下载所有图片
    """
    print("开始下载算法相关图片...")
    
    success_count = 0
    for img in algorithm_images:
        if download_image(img['url'], img['filename']):
            success_count += 1
    
    print(f"\n下载完成: {success_count}/{len(algorithm_images)} 张图片成功下载")

if __name__ == "__main__":
    main() 